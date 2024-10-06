

/*

 * Copyright (C) { Erkam Murat Bozkurt } - All Rights Reserved
 * 
 * This source code is protected under international copyright law.  All rights
 * reserved and protected by the copyright holders.
 * 
 * This file is confidential and only available to authorized individuals with the
 * permission of the copyright holders.  If you encounter this file and do not have
 * permission, please contact the copyright holders and delete this file.

*/

#include "Custom_TabArt.h"


 Custom_TabArt::Custom_TabArt(wxColour clr) : wxAuiDefaultTabArt()
 {
    this->page_close_icon = new wxBitmap(wxT("C:\\Program Files\\Pcynlitx\\icons\\close_tab.png"),

                             wxBITMAP_TYPE_ANY);

    std::string tabart_font = "Segoe UI";

    this->Default_Font = new wxFont(9,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,

                     wxFONTWEIGHT_NORMAL,false,wxString(tabart_font));

    this->m_tabCtrlHeight = 48;

    this->theme_clr = clr;
 }

 wxAuiTabArt * Custom_TabArt::Clone() {

       Custom_TabArt * TabArt_Pointer = new Custom_TabArt(this->theme_clr);

       return TabArt_Pointer;
 }

 Custom_TabArt::~Custom_TabArt(){

      this->page_close_icon->~wxBitmap();
 }

 void Custom_TabArt::DrawBackground(wxDC& dc, wxWindow *  wnd, const wxRect & rect) {

      dc.SetPen(wxPen(wxColour(240,240,240,0xff)));

      dc.SetBrush(wxColour(240,240,240,0xff));

      dc.DrawRectangle(rect.GetX(), rect.GetY(),rect.GetWidth(),rect.GetHeight());
 }

 void Custom_TabArt::DrawTab(wxDC & dc, wxWindow *wnd, const wxAuiNotebookPage &page,

                 const wxRect & in_rect, int close_button_state,

                 wxRect * out_tab_rect, wxRect * out_button_rect, int * x_extent)
 {

       wxCoord normal_textx,   normal_texty;

       wxCoord selected_textx, selected_texty;

       wxCoord texty;

       wxString caption = page.caption;



       dc.SetFont(*this->Default_Font);

       dc.GetTextExtent(caption, &selected_textx, &selected_texty);

       dc.GetTextExtent(caption, &normal_textx, &normal_texty);
 
       //caption = caption + " "; // more area for the string must be allocted
       

       // figure out the size of the tab
       wxSize tab_size = this->GetTabSize(dc,wnd,caption,page.bitmap,

                                    page.active,close_button_state,x_extent);

       wxCoord tab_height = tab_size.y+14;

       wxCoord tab_width  = tab_size.x;

       wxCoord tab_x = in_rect.x+1;

       wxCoord tab_y = in_rect.y+14;





       wxFont bld = *this->Default_Font;
       
       bld.SetFaceName(wxT("Segoe UI"));


       

       //bld.SetPixelSize(wxSize(0,14));


       wxFont normal = *this->Default_Font;

       normal.SetFaceName(wxT("Segoe UI"));


       if (page.active)
       {

           dc.SetFont(bld);

           texty = selected_texty;
       }
       else
       {
           dc.SetFont(normal);

           texty = normal_texty;
       }


       if (page.active)
       {
           // draw active tab

           // draw base background color

           wxRect r(tab_x, tab_y, tab_width-2, tab_height-3);

           dc.SetPen(wxPen(wxColour(155,155,165,0xff)));
            
           dc.SetBrush(wxColour(175,175,185,0xff));

           


           // DrawRectangle member function: The first two parameters indicate the coordinates
           // of the top left corner of the rectangle

           dc.DrawRectangle(r.x, r.y, r.width, r.height);

        }
        else{

                // draw inactive tab

                wxRect r(tab_x, tab_y,tab_width-2, tab_height-3);

                dc.SetPen(wxPen(wxColour(180, 180, 180)));

                dc.SetBrush(wxBrush(wxColour(210, 210, 210)));

                // DrawRectangle member function: The first two parameters indicate the coordinates
                // of the top left corner of the rectangle

                dc.DrawRectangle(r.x, r.y, r.width, r.height);
        }


        // draw close button 
        if (close_button_state != wxAUI_BUTTON_STATE_HIDDEN)
         {
             wxBitmap bmp;

             if (page.active){

                 bmp = *this->page_close_icon;
             }
             else{

                 wxSize bmp_size = this->page_close_icon->GetScaledSize();
                 bmp = m_disabledCloseBmp.GetBitmap(bmp_size);
            }

             wxRect rect(tab_x + tab_width - bmp.GetScaledWidth() - 10,
                         tab_y + (tab_height/2) - (bmp.GetScaledHeight()/2)-10,
                         bmp.GetScaledWidth()-3,
                         tab_height - 1);

             DrawButtons(dc,wxSize(1, 1), rect, bmp, *wxWHITE, close_button_state);

             *out_button_rect = rect;
         }



         wxString draw_text = page.caption;

         wxSize Text_Extend = dc.GetTextExtent(draw_text);

         int text_offset = tab_x + (tab_width-Text_Extend.x)/2;



         if(page.active){

            dc.SetTextForeground(wxColour(0,0,10));
         }
         else{

            dc.SetTextForeground(wxColour(25,25,25));
         }


         Text_Extend = dc.GetTextExtent(page.caption);

         if(page.active){

            text_offset = text_offset - 10;
         }
         else{

            text_offset = text_offset - 3;
         }



         dc.DrawText(draw_text,text_offset,

                 (tab_y + tab_height)/2 - (texty/2) + 1);


         *out_tab_rect = wxRect(tab_x, tab_y, tab_width, tab_height+14);

 }



 void Custom_TabArt::DrawButtons(wxDC& dc, const wxSize& offset,const wxRect& _rect,

                            const wxBitmap& bmp, const wxColour& bkcolour, int button_state)
  {
        wxRect rect = _rect;

        if (button_state == wxAUI_BUTTON_STATE_PRESSED)
        {
            rect.x += offset.x;
            rect.y += offset.y;
        }

        if (button_state == wxAUI_BUTTON_STATE_HOVER ||
            button_state == wxAUI_BUTTON_STATE_PRESSED)
        {
            dc.SetBrush(wxBrush(bkcolour.ChangeLightness(120)));
            dc.SetPen(wxPen(bkcolour.ChangeLightness(75)));

            // draw the background behind the button
            dc.DrawRectangle(rect.x, rect.y+7, bmp.GetScaledWidth()-offset.x-2,

                 bmp.GetScaledHeight()-offset.y);
        }

        // draw the button itself
        dc.DrawBitmap(bmp, rect.x, rect.y+6, true);
 }

 void Custom_TabArt::DrawButton(wxDC& dc,wxWindow* wnd,const wxRect& in_rect,

                    int bitmap_id,int button_state,int orientation, wxRect* out_rect)
 {

      wxBitmapBundle bb;
      wxRect rect;

      switch (bitmap_id)
      {
          case wxAUI_BUTTON_CLOSE:
              if (button_state & wxAUI_BUTTON_STATE_DISABLED)
                  bb = m_disabledCloseBmp;
              else
                  bb = m_activeCloseBmp;
              break;

          case wxAUI_BUTTON_LEFT:
              if (button_state & wxAUI_BUTTON_STATE_DISABLED)
                  bb = m_disabledLeftBmp;
              else
                  bb = m_activeLeftBmp;
              break;

          case wxAUI_BUTTON_RIGHT:
              if (button_state & wxAUI_BUTTON_STATE_DISABLED)
                  bb = m_disabledRightBmp;
              else
                  bb = m_activeRightBmp;
              break;

          case wxAUI_BUTTON_WINDOWLIST:
              if (button_state & wxAUI_BUTTON_STATE_DISABLED)
                  bb = m_disabledWindowListBmp;
              else
                  bb = m_activeWindowListBmp;
              break;
      }


      if (!bb.IsOk())
          return;


      const wxBitmap bmp = bb.GetBitmapFor(wnd);


      rect = in_rect;

      if (orientation == wxLEFT)
      {
          rect.SetX(in_rect.x);
          rect.SetY(((in_rect.y + in_rect.height)/2) - (bmp.GetScaledHeight()/2)-2);
          rect.SetWidth(bmp.GetScaledWidth());
          rect.SetHeight(bmp.GetScaledHeight());
      }
      else
      {
          rect = wxRect(in_rect.x + in_rect.width - bmp.GetScaledWidth(),
                      ((in_rect.y + in_rect.height)/2) - (bmp.GetScaledHeight()/2)-2,
                      bmp.GetScaledWidth(), bmp.GetScaledHeight());
      }


      this->DrawButtons(dc,wxSize(1,1), rect, bmp, *wxWHITE, button_state);

      *out_rect = rect;
 };
