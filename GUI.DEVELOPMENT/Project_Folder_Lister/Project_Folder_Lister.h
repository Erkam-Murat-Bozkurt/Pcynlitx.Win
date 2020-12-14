
#ifndef PROJECT_FOLDER_LISTER_H
#define PROJECT_FOLDER_LISTER_H

#include <wx/wx.h>
#include <wx/treectrl.h>
#include <wx/panel.h>
#include <wx/splitter.h>
#include <wx/sizer.h>
#include <wx/dir.h>
#include <wx/icon.h>
#include <wx/dialog.h>
#include <wx/window.h>
#include <cstdlib>
#include <wx/artprov.h>
#include <wx/msgout.h>
#include "Custom_wxTreeCtrl.h"

struct Tree_Item
{
   wxTreeItemId item_id;
   wxString Item_Path;
};

class Project_Folder_Lister
{
public:
  Project_Folder_Lister(Custom_wxTreeCtrl * TreeCtrl);

  virtual ~Project_Folder_Lister();

  void Load_Project_Directory(wxString Folder);

  void RemoveProjectDirectory();

  Custom_wxTreeCtrl * GetTreeCtrl();

  wxString GetItemPath(wxTreeItemId item_number);

  bool GetProjectDirectoryOpenStatus();

  void Expand_Root();

private:
  void Initialize_Properties(wxString Folder);

  void count_sub_directories(wxString Folder);

  void Append_Items(wxString Folder, wxTreeItemId Id);

  size_t Get_Sub_Directory_Name_Size(wxString Item);

  wxString Determine_Short_Path(wxString Item);

  bool Does_it_have_SubDir(wxString Folder);

  wxTreeItemId Append_Directory_To_Tree(wxTreeItemId Id, wxString Directory, wxString Path);

  wxTreeItemId Append_File_To_Tree(wxTreeItemId Id, wxString Directory, wxString Path);

  void Append_Files(wxString Folder, wxTreeItemId Id);

  void Count_Files(wxString Folder);

  size_t Short_Path_Name_Size;
  int sub_directory_number;
  int total_item_number;
  int item_counter;
  Custom_wxTreeCtrl * treeCtrl;
  wxImageList * imglist;
  Tree_Item * tree_item_list;
  wxString Short_Path;
  wxString Item_Path;
  bool is_project_directory_open;
  bool Memory_Delete_Condition;
  bool search_cond;
  bool does_it_have_sub_dir;
  wxTreeItemId appended_item_id;
};

#endif /* PROJECT_FOLDER_LISTER_H */
