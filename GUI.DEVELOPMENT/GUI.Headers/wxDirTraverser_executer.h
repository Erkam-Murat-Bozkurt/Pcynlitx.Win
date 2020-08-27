/*

Copyright ©  2019,  Erkam Murat Bozkurt

This file is part of the research project which is carried by Erkam Murat Bozkurt.

This is a free software: you can redistribute it and/or modify it under the terms
of the GNU General Public License as published by the Free Software Foundation
either version 3 of the License, or any later version.

This software is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program. If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef WXDIRTRAVERSER_EXECUTER_H
#define WXDIRTRAVERSER_EXECUTER_H

#include <wx/dir.h>

class wxDirTraverser_executer : public wxDirTraverser
{
public:
  wxDirTraverser_executer(wxArrayString & index) : Folder_Index (index) {}

  virtual ~wxDirTraverser_executer(){

      Folder_Index.Clear();
  };

  virtual wxDirTraverseResult OnFile(const wxString & filename){

      Folder_Index.Add(filename);

      return wxDIR_CONTINUE;
  }
  virtual wxDirTraverseResult OnDir(const wxString & dirname){

    Folder_Index.Add(dirname);

    return wxDIR_CONTINUE;
  }
  virtual wxDirTraverseResult OnOpenError(const wxString &openerrorname){

    Folder_Index.Add(openerrorname);

    return wxDIR_IGNORE;
  }
private:
  wxArrayString & Folder_Index;
};

#endif /* WXDIRTRAVERSER_EXECUTER_H */
