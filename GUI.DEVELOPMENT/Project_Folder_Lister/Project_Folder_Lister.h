
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
#include <wx/dataview.h>
#include <string>


struct Tree_Item
{
  wxDataViewItem item_number;
  wxString Item_Path;
};

class Project_Folder_Lister
{
public:
  Project_Folder_Lister(wxDataViewTreeCtrl * TreeCtrl);

  virtual ~Project_Folder_Lister();

  void Load_Project_Directory(wxString Folder);

  void RemoveProjectDirectory();

  wxDataViewTreeCtrl * GetTreeCtrl();

  wxString GetItemPath(wxDataViewItem item_number);

  bool GetProjectDirectoryOpenStatus();

  int GetTotalItemNum(wxString Folder);

  void Expand_Root();

  void Expand_Selected_Item();

  void Expand_Path(wxString path);

  wxDataViewItem GetItemId_FromPath(wxString path);
  
private:

  void Initialize_Properties();

  void count_sub_directories(wxString Folder);

  bool Is_Item_Already_Exist(wxString Path);

  void Append_Items(wxString Folder, wxDataViewItem Id);

  size_t Get_Sub_Directory_Name_Size(wxString Item);

  wxString Determine_Short_Path(wxString Item);

  bool Does_it_have_SubDir(wxString Folder);

  wxDataViewItem Append_Directory_To_Tree(wxDataViewItem Item, wxString Directory, wxString Path);

  wxDataViewItem Append_File_To_Tree(wxDataViewItem Item, wxString Directory, wxString Path);

  void Append_Files(wxString Folder, wxDataViewItem Item);

  void Count_Files(wxString Folder);

  size_t Short_Path_Name_Size;
  int sub_directory_number;
  int total_item_number;
  int item_counter;
  wxDataViewTreeCtrl * treeCtrl;
  Tree_Item * tree_item_list;
  wxString Short_Path;
  wxString Item_Path;
  bool is_project_directory_open;
  bool Memory_Delete_Condition;
  bool search_cond;
  bool does_it_have_sub_dir;
  wxDataViewItem appended_item;
  wxBitmap Folder_Icon;
  wxBitmap File_Icon;

};

#endif /* PROJECT_FOLDER_LISTER_H */
