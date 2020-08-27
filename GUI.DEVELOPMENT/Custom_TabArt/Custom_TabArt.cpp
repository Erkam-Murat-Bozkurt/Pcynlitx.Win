


#include "Custom_TabArt.h"


 Custom_TabArt::Custom_TabArt() : wxAuiDefaultTabArt()
 {
    this->page_close_icon = new wxBitmap(wxT("/usr/share/Pcynlitx/icons/close_tab.png"),

                             wxBITMAP_TYPE_ANY);
 }

 wxAuiTabArt * Custom_TabArt::Clone() {

       Custom_TabArt * TabArt_Pointer = new Custom_TabArt();

       return TabArt_Pointer;
 }

 Custom_TabArt::~Custom_TabArt(){

      this->page_close_icon->~wxBitmap();
 }

 void Custom_TabArt::DrawBackground(wxDC& dc, wxWindow *  wnd, const wxRect & rect) {

      dc.SetBrush(wxColour(235,235,235));

      dc.DrawRectangle(rect.GetX()-2, rect.GetY()-2,rect.GetWidth()+5,rect.GetHeight()+5);
 }

 void Custom_TabArt::DrawTab(wxDC & dc, wxWindow *wnd, const wxAuiNotebookPage &page,

                 const wxRect & in_rect, int close_button_state,

                 wxRect *out_tab_rect, wxRect * out_button_rect, int * x_extent)
 {

        wxCoord normal_textx, normal_texty;

        wxCoord selected_textx, selected_texty;

        wxCoord textx, texty;

        wxString caption = page.caption;

        dc.SetFont(this->m_selectedFont);

        dc.GetTextExtent(caption, &selected_textx, &selected_texty);

        dc.SetFont(this->m_normalFont);

        dc.GetTextExtent(caption, &normal_textx, &normal_texty);

        // figure out the size of the tab
        wxSize tab_size = GetTabSize(dc,wnd,page.caption,page.bitmap,

                                     page.active,close_button_state,x_extent);

        wxCoord tab_height = tab_size.y;

        wxCoord tab_width = tab_size.x;

        wxCoord tab_x = in_rect.x-2;

        wxCoord tab_y = in_rect.y;

        if (page.active)
        {
            dc.SetFont(m_normalFont);

            texty = selected_texty;
        }
        else
        {
               dc.SetFont(m_normalFont);

               texty = normal_texty;
        }


        wxPoint border_points[6];

        if (page.active)
        {
             // draw active tab

             // draw base background color

            wxRect r(tab_x, tab_y, tab_width, tab_height+5);

            dc.SetPen(wxPen(wxColour(128,139,150)));

            dc.SetBrush(wxBrush(wxColour(128,139,150)));

            // DrawRectangle member function: The first two parameters indicate the coordinates
            // of the top left corner of the rectangle

            dc.DrawRectangle(r.x+3, r.y+3, r.width-2, r.height);


            border_points[0] = wxPoint(tab_x+3,tab_y+tab_height+7); // left bottom corner

            border_points[1] = wxPoint(tab_x+3,tab_y+4); // left top corner

            border_points[2] = wxPoint(tab_x+3,tab_y+3); // right top corner

            border_points[3] = wxPoint(tab_x+tab_width,tab_y+3);

            border_points[4] = wxPoint(tab_x+tab_width,tab_y+4);

            border_points[5] = wxPoint(tab_x+tab_width,tab_y+tab_height+7);


            dc.SetPen(wxPen(wxColour(150,150,150)));

            dc.SetBrush(*wxTRANSPARENT_BRUSH);

            dc.DrawPolygon(WXSIZEOF(border_points), border_points);

            dc.SetBrush(wxColour(150,150,150));
       }
       else{

              // draw inactive tab

              wxRect r(tab_x, tab_y,tab_width, tab_height+5);

              dc.SetPen(wxPen(wxColour(150,150,150)));

              dc.SetBrush(wxBrush(wxColour(150,150,150)));

              // DrawRectangle member function: The first two parameters indicate the coordinates
              // of the top left corner of the rectangle

              dc.DrawRectangle(r.x+3, r.y+3, r.width-2, r.height);


              border_points[0] = wxPoint(tab_x+3,tab_y+tab_height+7); // left bottom corner

              border_points[1] = wxPoint(tab_x+3,tab_y+4); // left top corner

              border_points[2] = wxPoint(tab_x+3,tab_y+3); // right top corner

              border_points[3] = wxPoint(tab_x+tab_width,tab_y+3);

              border_points[4] = wxPoint(tab_x+tab_width,tab_y+4);

              border_points[5] = wxPoint(tab_x+tab_width,tab_y+tab_height+7);

              dc.SetPen(wxPen(wxColour(150,150,150)));

              dc.SetBrush(*wxTRANSPARENT_BRUSH);

              dc.DrawPolygon(WXSIZEOF(border_points), border_points);
       }

       int close_button_width = 0;

       // draw close button if necessary
       if (close_button_state != wxAUI_BUTTON_STATE_HIDDEN)
       {
           wxBitmap bmp;
           if (page.active)

               bmp = *this->page_close_icon;

           else
               bmp = m_disabledCloseBmp;

           wxRect rect(tab_x + tab_width - bmp.GetScaledWidth() - 8,
                       tab_y + (tab_height/2) - (bmp.GetScaledHeight()/2) + 6,
                       bmp.GetScaledWidth(),
                       tab_height - 1);
           DrawButtons(dc,wxSize(1, 1), rect, bmp, *wxWHITE, close_button_state);

           *out_button_rect = rect;
           close_button_width = bmp.GetScaledWidth();
       }

       wxString draw_text = page.caption;

       wxSize Text_Extend = dc.GetTextExtent(draw_text);


       int text_offset = tab_x + (tab_width-Text_Extend.x)/2;

       // set minimum text offset

       if (text_offset < tab_x + tab_height){

           text_offset = tab_x + tab_height -12;
       }


       if(page.active){

           dc.SetTextForeground(wxColour(220,220,220));
       }
       else{

             dc.SetTextForeground(wxColour(220,220,220));
       }


       dc.DrawText(draw_text,
             text_offset,
             (tab_y + tab_height)/2 - (texty/2) + 4);

       *out_tab_rect = wxRect(tab_x, tab_y, tab_width, tab_height);
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
            dc.DrawRectangle(rect.x, rect.y, bmp.GetScaledWidth()-offset.x, bmp.GetScaledHeight()-offset.y);
        }

        // draw the button itself
        dc.DrawBitmap(bmp, rect.x, rect.y, true);
 }



 void Custom_TabArt::DrawButton(wxDC& dc,wxWindow* wnd,const wxRect& in_rect,

                    int bitmap_id,int button_state,int orientation, wxRect* out_rect)
 {

      wxBitmap bmp;
      wxRect rect;

      switch (bitmap_id)
      {
          case wxAUI_BUTTON_CLOSE:
              if (button_state & wxAUI_BUTTON_STATE_DISABLED)
                  bmp = m_disabledCloseBmp;
              else
                  bmp = m_activeCloseBmp;
              break;

          case wxAUI_BUTTON_LEFT:
              if (button_state & wxAUI_BUTTON_STATE_DISABLED)
                  bmp = m_disabledLeftBmp;
              else
                  bmp = m_activeLeftBmp;
              break;

          case wxAUI_BUTTON_RIGHT:
              if (button_state & wxAUI_BUTTON_STATE_DISABLED)
                  bmp = m_disabledRightBmp;
              else
                  bmp = m_activeRightBmp;
              break;

          case wxAUI_BUTTON_WINDOWLIST:
              if (button_state & wxAUI_BUTTON_STATE_DISABLED)
                  bmp = m_disabledWindowListBmp;
              else
                  bmp = m_activeWindowListBmp;
              break;
      }


      if (!bmp.IsOk())
          return;

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

      //dc.DrawBitmap(bmp, rect.x, rect.y, true);

      this->DrawButtons(dc,wxSize(1, 1), rect, bmp, *wxWHITE, button_state);

      *out_rect = rect;
 };
