
{
    $Id: signalf.inc,v 1.1.2.2 2003/04/24 09:28:12 pierre Exp $
    This file is part of the Free Pascal run time library.
    Copyright (c) 1999-2000 by Jonas Maebe,
    member of the Free Pascal development team.

    See the file COPYING.FPC, included in this distribution,
    for details about the copyright.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

 **********************************************************************}

function  reenable_signal(sig : longint) : boolean;
var
  e,oe : SigSet;
  i,j : byte;
begin
  fillchar(e,sizeof(e),#0);
  fillchar(oe,sizeof(oe),#0);
  { set is 1 based PM }
  dec(sig);
  i:=sig mod 32;
  j:=sig div 32;
  e[j]:=1 shl i;
  do_syscall(syscall_nr_sigprocmask,longint(SIG_UNBLOCK),longint(@e),longint(@oe));
  reenable_signal:=errno=0;
end;

{
  $Log: signalf.inc,v $
  Revision 1.1.2.2  2003/04/24 09:28:12  pierre
   * fix bug in reenable_signal

  Revision 1.1.2.1  2003/01/31 22:02:11  pierre
   * allow several exceptions to be honored

}
