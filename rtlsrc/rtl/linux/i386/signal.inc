{
    $Id: signal.inc,v 1.1.2.1 2002/10/10 19:31:28 pierre Exp $
    This file is part of the Free Pascal run time library.
    Copyright (c) 1999-2000 by Jonas Maebe,
    member of the Free Pascal development team.

    See the file COPYING.FPC, included in this distribution,
    for details about the copyright.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

 **********************************************************************}

{$packrecords C}

{********************
      Signal
********************}

Const
  { For sending a signal }
  SA_NOCLDSTOP = 1;
  SA_SHIRQ     = $04000000;
  SA_STACK     = $08000000;
  SA_RESTART   = $10000000;
  SA_INTERRUPT = $20000000;
  SA_NOMASK    = $40000000;
  SA_ONESHOT   = $80000000;

  SIG_BLOCK   = 0;
  SIG_UNBLOCK = 1;
  SIG_SETMASK = 2;

  SIG_DFL = 0 ;
  SIG_IGN = 1 ;
  SIG_ERR = -1 ;

  SIGHUP     = 1;
  SIGINT     = 2;
  SIGQUIT    = 3;
  SIGILL     = 4;
  SIGTRAP    = 5;
  SIGABRT    = 6;
  SIGIOT     = 6;
  SIGBUS     = 7;
  SIGFPE     = 8;
  SIGKILL    = 9;
  SIGUSR1    = 10;
  SIGSEGV    = 11;
  SIGUSR2    = 12;
  SIGPIPE    = 13;
  SIGALRM    = 14;
  SIGTerm    = 15;
  SIGSTKFLT  = 16;
  SIGCHLD    = 17;
  SIGCONT    = 18;
  SIGSTOP    = 19;
  SIGTSTP    = 20;
  SIGTTIN    = 21;
  SIGTTOU    = 22;
  SIGURG     = 23;
  SIGXCPU    = 24;
  SIGXFSZ    = 25;
  SIGVTALRM  = 26;
  SIGPROF    = 27;
  SIGWINCH   = 28;
  SIGIO      = 29;
  SIGPOLL    = SIGIO;
  SIGPWR     = 30;
  SIGUNUSED  = 31;


const
  SI_PAD_SIZE	= ((128 div sizeof(longint)) - 3);

type
  tfpreg = record
	  significand: array[0..3] of word;
	  exponent: word;
  end;

  pfpstate = ^tfpstate;
  tfpstate = record
	   cw, sw, tag, ipoff, cssel, dataoff, datasel: cardinal;
	   st: array[0..7] of tfpreg;
	   status: cardinal;
  end;

  PSigContextRec = ^SigContextRec;
  SigContextRec = record
    gs, __gsh: word;
    fs, __fsh: word;
    es, __esh: word;
    ds, __dsh: word;
    edi: cardinal;
    esi: cardinal;
    ebp: cardinal;
    esp: cardinal;
    ebx: cardinal;
    edx: cardinal;
    ecx: cardinal;
    eax: cardinal;
    trapno: cardinal;
    err: cardinal;
    eip: cardinal;
    cs, __csh: word;
    eflags: cardinal;
    esp_at_signal: cardinal;
    ss, __ssh: word;
    fpstate: pfpstate;
    oldmask: cardinal;
    cr2: cardinal;
  end;

(*
  PSigInfoRec = ^SigInfoRec;
  SigInfoRec = record
    si_signo: longint;
    si_errno: longint;
    si_code: longint;

    case longint of
      0:
        (pad: array[SI_PAD_SIZE] of longint);
      1: { kill }
        ( kill: record
            pid: longint;  { sender's pid }
            uid : longint; { sender's uid }
          end );
      2: { POSIX.1b timers }
        ( timer : record
            timer1 : cardinal;
            timer2 : cardinal;
           end );
      3: { POSIX.1b signals }
        ( rt : record
            pid : longint;    { sender's pid }
            uid : longint;    { sender's uid }
            sigval : longint;
         end );
      4: { SIGCHLD }
        ( sigchld : record
          pid : longint;    { which child }
          uid : longint;    { sender's uid }
          status : longint; { exit code }
          utime : timeval;
          stime : timeval;
         end );
      5: { SIGILL, SIGFPE, SIGSEGV, SIGBUS }
        ( sigfault : record
            addr : pointer;{ faulting insn/memory ref. }
          end );
      6:
        ( sigpoll : record
            band : longint; { POLL_IN, POLL_OUT, POLL_MSG }
            fd : longint;
          end );
  end;
*)

  SignalHandler   = Procedure(Sig : Longint);cdecl;
  PSignalHandler  = ^SignalHandler;
  SignalRestorer  = Procedure;cdecl;
  PSignalRestorer = ^SignalRestorer;
  TSigAction = procedure(Sig: Longint; SigContext: SigContextRec);cdecl;

  SigSet  = Longint;
  PSigSet = ^SigSet;

  SigActionRec = packed record
    Handler  : record
      case byte of
        0: (Sh: SignalHandler);
        1: (Sa: TSigAction);
      end;
    Sa_Mask     : SigSet;
    Sa_Flags    : Longint;
    Sa_restorer : SignalRestorer; { Obsolete - Don't use }
  end;
  PSigActionRec = ^SigActionRec;

Procedure SigAction(Signum:Integer;Act,OldAct:PSigActionRec );
{
  Change action of process upon receipt of a signal.
  Signum specifies the signal (all except SigKill and SigStop).
  If Act is non-nil, it is used to specify the new action.
  If OldAct is non-nil the previous action is saved there.
}
Var
  sr : Syscallregs;
begin
  sr.reg2:=Signum;
  sr.reg3:=Longint(act);
  sr.reg4:=Longint(oldact);
  SysCall(Syscall_nr_sigaction,sr);
end;

{
  $Log: signal.inc,v $
  Revision 1.1.2.1  2002/10/10 19:31:28  pierre
   * update those files that are unused currently

  Revision 1.1  2000/07/13 06:30:55  michael
  + Initial import

  Revision 1.2  2000/03/31 23:11:23  pierre
   * TSigAction Context param is the full record not a pointer

  Revision 1.1  2000/03/31 13:24:28  jonas
    * signal handling using sigaction when compiled with -dnewsignal
      (allows multiple signals to be received in one run)

}
