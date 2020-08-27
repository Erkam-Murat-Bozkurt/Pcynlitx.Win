
#ifndef PROJECT_FOLDER_LISTER_H
#define PROJECT_FOLDER_LISTER_H

#include <wx/wx.h>
#include <wx/panel.h>
#include <wx/splitter.h>
#include <wx/sizer.h>
#include <wx/dir.h>
#include <wx/dataview.h>
#include <wx/icon.h>
#include <wx/dialog.h>
#include "wxDirTraverser_executer.h"
#include "Custom_wxDataViewTreeCtrl.h"

struct Tree_Item
{
   wxDataViewItem item_number;
   wxString Item_Path;
};

class Project_Folder_Lister
{
public:
  Project_Folder_Lister(Custom_wxDataViewTreeCtrl * TreeCtrl);
  virtual ~Project_Folder_Lister();
  void Load_Project_Directory(wxString Folder);
  void RemoveProjectDirectory();
  Custom_wxDataViewTreeCtrl * GetDataViewTreeCtrl();
  wxString GetItemPath(wxDataViewItem item_number);
  bool GetProjectDirectoryOpenStatus();
  void Clear_Dynamic_Memory();
private:
  int  Determine_Tree_Item_String(wxString Item_String, wxString & Tree_Item_String);
  void Determine_Root_Item_String(wxString Item_String, wxString & Root_Item_String, int Tree_Item_Size);
  void Determine_Root_Item(wxDataViewItem & Root_Item, wxString & Root_Item_String, wxString Item_String, wxString Folder, int item_counter);
  Custom_wxDataViewTreeCtrl * tree_control;
  Tree_Item * tree_item_list;
  wxDir * dirCtrl;
  wxDirTraverser_executer * dir_traverser;
  wxArrayString Folder_Index;
  wxString Item_Path;
  wxWindow * win_pointer;
  int Total_Item_Number;
  int Tree_Item_Size;
  size_t Sub_Directory_Number;
  size_t Sub_File_Number;
  bool is_project_directory_open;
  bool Memory_Delete_Condition;
};

#endif /* PROJECT_FOLDER_LISTER_H */
