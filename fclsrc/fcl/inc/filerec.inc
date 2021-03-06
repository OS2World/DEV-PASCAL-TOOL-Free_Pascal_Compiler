{
    $Id: filerec.inc,v 1.3 2002/09/07 15:15:24 peter Exp $
    This file is part of the Free Pascal run time library.
    Copyright (c) 1999-2000 by the Free Pascal development team

    FileRec record definition


    See the file COPYING.FPC, included in this distribution,
    for details about the copyright.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

 **********************************************************************}

{
  This file contains the definition of the filerec record.
  It is put separately, so it is available outside the system
  unit without sacrificing TP compatibility.
}

const
  filerecnamelength = 255;
type
  FileRec = Packed Record
    Handle,
    Mode,
    RecSize   : longint;
    _private  : array[1..32] of byte;
    UserData  : array[1..16] of byte;
    name      : array[0..filerecnamelength] of char;
  End;

{
  $Log: filerec.inc,v $
  Revision 1.3  2002/09/07 15:15:24  peter
    * old logs removed and tabs fixed

}
