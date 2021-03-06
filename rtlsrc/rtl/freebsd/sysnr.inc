{
    $Id: sysnr.inc,v 1.1.2.6 2003/03/13 22:02:27 marco Exp $
    This file is part of the Free Pascal run time library.
    Copyright (c) 1999-2000 by Michael Van Canneyt,
    member of the Free Pascal development team.

    See the file COPYING.FPC, included in this distribution,
    for details about the copyright.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

 **********************************************************************}

const
{ Crude converted FreeBSD  4.0-release syscall.h. Copy and paste if you
 checked the function.
 syscall_nr_syscall                     =  0;
 syscall_nr_exit                        =  1;
 syscall_nr_fork                        =  2;
 syscall_nr_read                        =  3;
 syscall_nr_write                       =  4;
 syscall_nr_open                        =  5;
 syscall_nr_close                       =  6;
 syscall_nr_wait4                       =  7;
 syscall_nr_link                        =  9;
 syscall_nr_unlink                      = 10;
 syscall_nr_chdir                       = 12;
 syscall_nr_fchdir                      = 13;
 syscall_nr_mknod                       = 14;
 syscall_nr_chmod                       = 15;
 syscall_nr_chown                       = 16;
 syscall_nr_break                       = 17;
 syscall_nr_getfsstat                   = 18;
 syscall_nr_getpid                      = 20;
 syscall_nr_mount                       = 21;
 syscall_nr_unmount                     = 22;
 syscall_nr_setuid                      = 23;
 syscall_nr_getuid                      = 24;
 syscall_nr_geteuid                     = 25;
 syscall_nr_ptrace                      = 26;
 syscall_nr_recvmsg                     = 27;
 syscall_nr_sendmsg                     = 28;
 syscall_nr_getpeername                 = 31;
 syscall_nr_getsockname                 = 32;
 syscall_nr_access                      = 33;
 syscall_nr_chflags                     = 34;
 syscall_nr_fchflags                    = 35;
 syscall_nr_sync                        = 36;
 syscall_nr_kill                        = 37;
 syscall_nr_getppid                     = 39;
 syscall_nr_dup                         = 41;
 syscall_nr_pipe                        = 42;
 syscall_nr_getegid                     = 43;
 syscall_nr_profil                      = 44;
 syscall_nr_ktrace                      = 45;
 syscall_nr_getgid                      = 47;
 syscall_nr_getlogin                    = 49;
 syscall_nr_setlogin                    = 50;
 syscall_nr_acct                        = 51;

 syscall_nr_ioctl                       = 54;
 syscall_nr_reboot                      = 55;
 syscall_nr_revoke                      = 56;
 syscall_nr_symlink                     = 57;
 syscall_nr_readlink                    = 58;
 syscall_nr_execve                      = 59;
 syscall_nr_umask                       = 60;
 syscall_nr_chroot                      = 61;
 syscall_nr_msync                       = 65;
 syscall_nr_vfork                       = 66;
 syscall_nr_sbrk                        = 69;
 syscall_nr_sstk                        = 70;
 syscall_nr_vadvise                     = 72;
 syscall_nr_mprotect                    = 74;
 syscall_nr_madvise                     = 75;
 syscall_nr_mincore                     = 78;
 syscall_nr_getgroups                   = 79;
 syscall_nr_setgroups                   = 80;
 syscall_nr_getpgrp                     = 81;
 syscall_nr_setpgid                     = 82;

 syscall_nr_swapon                      = 85;

 syscall_nr_getdtablesize               = 89;
 syscall_nr_dup2                        = 90;
 syscall_nr_fcntl                       = 92;
 syscall_nr_select                      = 93;
 syscall_nr_fsync                       = 95;
 syscall_nr_setpriority                 = 96;
 syscall_nr_connect                     = 98;
 syscall_nr_getpriority                 =100;
 syscall_nr_setsockopt                  =105;
 syscall_nr_gettimeofday                =116;
 syscall_nr_getrusage                   =117;
 syscall_nr_readv                       =120;
 syscall_nr_writev                      =121;
 syscall_nr_settimeofday                =122;
 syscall_nr_fchown                      =123;
 syscall_nr_fchmod                      =124;
 syscall_nr_setreuid                    =126;
 syscall_nr_setregid                    =127;
 syscall_nr_rename                      =128;
 syscall_nr_flock                       =131;
 syscall_nr_mkfifo                      =132;
 syscall_nr_mkdir                       =136;
 syscall_nr_rmdir                       =137;
 syscall_nr_utimes                      =138;
 syscall_nr_adjtime                     =140;
 syscall_nr_setsid                      =147;
 syscall_nr_quotactl                    =148;
 syscall_nr_nfssvc                      =155;
 syscall_nr_statfs                      =157;
 syscall_nr_fstatfs                     =158;
 syscall_nr_getfh                       =161;
 syscall_nr_getdomainname               =162;
 syscall_nr_setdomainname               =163;
 syscall_nr_uname                       =164;
 syscall_nr_rtprio                      =166;
 syscall_nr_semsys                      =169;
 syscall_nr_msgsys                      =170;
 syscall_nr_shmsys                      =171;
 syscall_nr_pread                       =173;
 syscall_nr_pwrite                      =174;
 syscall_nr_ntp_adjtime                 =176;
 syscall_nr_setgid                      =181;
 syscall_nr_setegid                     =182;
 syscall_nr_seteuid                     =183;
 syscall_nr_stat                        =188;
 syscall_nr_fstat                       =189;
 syscall_nr_lstat                       =190;
 syscall_nr_pathconf                    =191;
 syscall_nr_fpathconf                   =192;
 syscall_nr_getrlimit                   =194;
 syscall_nr_setrlimit                   =195;
 syscall_nr_mmap                        =197;
 syscall_nr___syscall                   =198;
 syscall_nr_lseek                       =199;
 syscall_nr_truncate                    =200;
 syscall_nr_ftruncate                   =201;
 syscall_nr___sysctl                    =202;
 syscall_nr_mlock                       =203;
 syscall_nr_munlock                     =204;
 syscall_nr_undelete                    =205;
 syscall_nr_futimes                     =206;
 syscall_nr_getpgid                     =207;
 syscall_nr_poll                        =209;
 syscall_nr___semctl                    =220;
 syscall_nr_semget                      =221;
 syscall_nr_semop                       =222;
 syscall_nr_semconfig                   =223;
 syscall_nr_msgctl                      =224;
 syscall_nr_msgget                      =225;
 syscall_nr_msgsnd                      =226;
 syscall_nr_msgrcv                      =227;
 syscall_nr_shmat                       =228;
 syscall_nr_shmctl                      =229;
 syscall_nr_shmdt                       =230;
 syscall_nr_shmget                      =231;
 syscall_nr_clock_gettime               =232;
 syscall_nr_clock_settime               =233;
 syscall_nr_clock_getres                =234;
 syscall_nr_nanosleep                   =240;
 syscall_nr_minherit                    =250;
 syscall_nr_openbsd_poll                =252;
 syscall_nr_issetugid                   =253;
 syscall_nr_lchown                      =254;
 syscall_nr_getdents                    =272;
 syscall_nr_lchmod                      =274;
 syscall_nr_netbsd_lchown               =275;
 syscall_nr_lutimes                     =276;
 syscall_nr_netbsd_msync                =277;
 syscall_nr_nstat                       =278;
 syscall_nr_nfstat                      =279;
 syscall_nr_nlstat                      =280;
 syscall_nr_fhstatfs                    =297;
 syscall_nr_fhopen                      =298;
 syscall_nr_fhstat                      =299;
 syscall_nr_modnext                     =300;
 syscall_nr_modstat                     =301;
 syscall_nr_modfnext                    =302;
 syscall_nr_modfind                     =303;
 syscall_nr_kldload                     =304;
 syscall_nr_kldunload                   =305;
 syscall_nr_kldfind                     =306;
 syscall_nr_kldnext                     =307;
 syscall_nr_kldstat                     =308;
 syscall_nr_kldfirstmod                 =309;
 syscall_nr_getsid                      =310;
 syscall_nr_setresuid                   =311;
 syscall_nr_setresgid                   =312;
 syscall_nr_aio_return                  =314;
 syscall_nr_aio_suspend                 =315;
 syscall_nr_aio_cancel                  =316;
 syscall_nr_aio_error                   =317;
 syscall_nr_aio_read                    =318;
 syscall_nr_aio_write                   =319;
 syscall_nr_lio_listio                  =320;
 syscall_nr_yield                       =321;
 syscall_nr_thr_sleep                   =322;
 syscall_nr_thr_wakeup                  =323;
 syscall_nr_mlockall                    =324;
 syscall_nr_munlockall                  =325;
 syscall_nr___getcwd                    =326;
 syscall_nr_sched_setparam              =327;
 syscall_nr_sched_getparam              =328;
 syscall_nr_sched_setscheduler          =329;
 syscall_nr_sched_getscheduler          =330;
 syscall_nr_sched_yield                 =331;
 syscall_nr_sched_get_priority_max      =332;
 syscall_nr_sched_get_priority_min      =333;
 syscall_nr_sched_rr_get_interval       =334;
 syscall_nr_utrace                      =335;
 syscall_nr_sendfile                    =336;
 syscall_nr_kldsym                      =337;
 syscall_nr_jail                        =338;
 syscall_nr_sigprocmask                 =340;
 syscall_nr_sigsuspend                  =341;
 syscall_nr_sigaction                   =342;
 syscall_nr_sigpending                  =343;
 syscall_nr_sigreturn                   =344;
 syscall_nr___acl_get_file              =347;
 syscall_nr___acl_set_file              =348;
 syscall_nr___acl_get_fd                =349;
 syscall_nr___acl_set_fd                =350;
 syscall_nr___acl_delete_file           =351;
 syscall_nr___acl_delete_fd             =352;
 syscall_nr___acl_aclcheck_file         =353;
 syscall_nr___acl_aclcheck_fd           =354;
 syscall_nr_extattrctl                  =355;
 syscall_nr_extattr_set_file            =356;
 syscall_nr_extattr_get_file            =357;
 syscall_nr_extattr_delete_file         =358;
 syscall_nr_aio_waitcomplete            =359;
 syscall_nr_getresuid                   =360;
 syscall_nr_getresgid                   =361;
 syscall_nr_MAXSYSCALL                  =362;

}

{More or less checked BSD syscalls}

 syscall_nr_accept                      =  30;
 syscall_nr_access                      =  33;
 syscall_nr_bind                        = 104;
 syscall_nr_chdir                       =  12;
 syscall_nr_chmod                       =  15;
 syscall_nr_chown                       =  16;
 syscall_nr_close                       =   6;
 syscall_nr_connect                     =  98;
 syscall_nr_dup                         =  41;
 syscall_nr_dup2                        =  90;
 syscall_nr_execve                      =  59;
 syscall_nr_exit                        =   1;
 syscall_nr_fcntl                       =  92;
 syscall_nr_flock                       = 131;
 syscall_nr_fork                        =   2;
 syscall_nr_fstat                       = 189;
 syscall_nr_fstatfs                     = 158;
 syscall_nr_fsync                       =  95;
 syscall_nr_ftruncate                   = 201;
 syscall_nr_getdents                    = 272;
 syscall_nr_getegid                     =  43;
 syscall_nr_geteuid                     =  25;
 syscall_nr_getgid                      =  47;
 syscall_nr_getpeername                 =  31;
 syscall_nr_getpid                      =  20;
 syscall_nr_getppid                     =  39;
 syscall_nr_getpriority                 = 100;
 syscall_nr_getsockname                 =  32;
 syscall_nr_gettimeofday                = 116;
 syscall_nr_getuid                      =  24;
 syscall_nr_ioctl                       =  54;
 syscall_nr_kill                        =  37;
 syscall_nr_link                        =   9;
 syscall_nr_listen                      = 106;
 syscall_nr_lseek                       = 199;
 syscall_nr_lstat                       = 190;
 syscall_nr_mkdir                       = 136;
 syscall_nr_mknod                       =  14;
 syscall_nr_mmap                        = 197;
 syscall_nr_open                        =   5;
 syscall_nr_pipe                        =  42;
 syscall_nr_read                        =   3;
 syscall_nr_readlink                    =  58;
 syscall_nr_recvfrom                    =  29;
 syscall_nr_rename                      = 128;
 syscall_nr_rmdir                       = 137;
 syscall_nr_select                      =  93;
 syscall_nr_sendto                      = 133;
 syscall_nr_setpriority                 =  96;
 syscall_nr_setsockopt                  = 105;
 syscall_nr_shutdown                    = 134;
 syscall_nr_sigaction                   = 342;
 syscall_nr_sigpending                  = 343;
 syscall_nr_sigprocmask                 = 340;
 syscall_nr_sigsuspend                  = 341;
 syscall_nr_socket                      =  97;
 syscall_nr_socketpair                  = 135;
 syscall_nr_stat                        = 188;
 syscall_nr_statfs                      = 157;
 syscall_nr_symlink                     =  57;
 syscall_nr_umask                       =  60;
 syscall_nr_unlink                      =  10;
 syscall_nr_utimes                      = 138;
 syscall_nr_waitpid                     =   7;
 syscall_nr_write                       =   4;
 syscall_nr_munmap                      =  73;
 syscall_nr_getsockopt                  = 118;
 syscall_nr_rfork                       = 251;
 syscall_nr_nanosleep                   = 240;
 syscall_nr_sysarch                     = 165;
 syscall_nr_getdirentries                =196;
 syscall_nr_setitimer                   = 83;
 syscall_nr_getitimer                   = 86;
 syscall_nr_sigaltstack                 = 53;
{
  $Log: sysnr.inc,v $
  Revision 1.1.2.6  2003/03/13 22:02:27  marco
   * sigaltstack syscall initial version

  Revision 1.1.2.5  2002/02/19 14:37:54  marco
   * Changes to support Alarm()

  Revision 1.1.2.4  2001/03/14 17:19:10  marco
   * Readdir compiles (some conflicts in Linux). Untested. Use NewReaddir to enable

  Revision 1.1.2.3  2001/01/23 06:38:50  marco
   * ioperm for FreeBSD. I/O back to Linux

  Revision 1.1.2.2  2000/10/24 12:13:22  pierre
   + syscall_nr_nanosleep

  Revision 1.1.2.1  2000/09/16 11:19:08  marco
   * Moved files from BSD to FreeBSD directory, with some small changes

  Revision 1.1.2.1  2000/09/10 16:12:14  marco
  Initial signals, sockets and clone

  Revision 1.1  2000/07/13 06:30:33  michael
  + Initial import

  Revision 1.4  2000/04/10 15:46:52  marco
   * worked all day. probably a lot changed

  Revision 1.2  2000/04/05 13:59:10  marco
   * added constants for syscall.inc

  Revision 1.1  2000/04/05 13:06:24  marco
   * Initial version. (copied from linux.) Patch for BSD not ready yeT

  Revision 1.5  2000/02/09 16:59:32  peter
    * truncated log

  Revision 1.4  2000/01/07 16:41:41  daniel
    * copyright 2000

  Revision 1.3  2000/01/07 16:32:28  daniel
    * copyright 2000 added

}