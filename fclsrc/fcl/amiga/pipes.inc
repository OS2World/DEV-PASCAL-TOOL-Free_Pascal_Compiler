{
    $Id: pipes.inc,v 1.1 2002/11/11 15:31:35 carl Exp $
    This file is part of the Free Pascal run time library.
    Copyright (c) 1999-2000 by Michael Van Canneyt

    AmigaOS specific part of pipe stream.

    See the file COPYING.FPC, included in this distribution,
    for details about the copyright.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

 **********************************************************************}

// Unsupported for the moment...

Function CreatePipeHandles (Var Inhandle,OutHandle : Longint) : Boolean;

begin
  Result := False;
end;
{
  $Log: pipes.inc,v $
  Revision 1.1  2002/11/11 15:31:35  carl
    + initial revision for amiga


}
