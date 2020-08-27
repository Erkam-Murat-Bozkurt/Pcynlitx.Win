
#ifndef MENU_BAR_OPTIONS_H
#define MENU_BAR_OPTIONS_H

#include <wx/wx.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/menuitem.h>
#include <wx/string.h>
#include "Event_ID_Numbers.h"

class Menu_Bar_Options
{
public:
  Menu_Bar_Options();
  virtual ~Menu_Bar_Options();
  wxMenuBar * Get_MenuBar();
private:
  wxMenu  * File_Menu;
  wxMenu  * Help_Menu;;
  wxMenu  * Launch_Menu;
  wxMenu  * Edit;
  wxMenu  * View_Menu;
  wxMenu  * Library_Description_Menu;
  wxMenu  * Compiler_Description_Menu;
  wxMenuBar * Menu_Bar;
};

#endif /* MENU_BAR_OPTIONS_H */
