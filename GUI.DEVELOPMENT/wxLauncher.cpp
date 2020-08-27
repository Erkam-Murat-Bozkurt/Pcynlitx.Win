
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


#include <wx/wx.h>
#include <wx/aui/framemanager.h>
#include <wx/aui/aui.h>
#include <wx/aui/auibar.h>
#include <wx/aui/auibook.h>
#include <wx/aui/dockart.h>
#include <wx/dnd.h>
#include <wx/icon.h>
#include <wx/font.h>
#include <wx/splitter.h>
#include <wx/treectrl.h>
#include <wx/dirctrl.h>
#include <wx/dir.h>
#include <wx/splitter.h>
#include <wx/listbook.h>
#include <wx/listctrl.h>
#include <wx/string.h>
#include "MainFrame.h"
#include "Intro_Page_Loader.h"
#include "Event_ID_Numbers.h"

class wxLauncher : public wxApp
{
public:
  virtual bool OnInit();
  virtual ~wxLauncher();
  MainFrame * Frame;
  wxIcon * Frame_Icon;
};

DECLARE_APP(wxLauncher)

IMPLEMENT_APP(wxLauncher)

wxLauncher::~wxLauncher(){

    if(this->HasPendingEvents()){

       this->DeletePendingEvents();
    }

    delete this->Frame_Icon;
}


bool wxLauncher::OnInit(){

     this->SetExitOnFrameDelete(true);

     this->Frame = new MainFrame();

     this->SetTopWindow(this->Frame);

     if(this->Frame)
     {
         this->Frame_Icon = new wxIcon(wxT("/usr/share/Pcynlitx/icons/pcynlitx.png"));

         this->Frame->SetIcon(*this->Frame_Icon);

         this->Frame->SetLabel(wxT("PCYNLITX"));

         this->Frame->Centre(wxBOTH);

         this->Frame->Show(true);

         return true;
     }
     else{

         return false;
     }
}
