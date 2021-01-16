
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

#ifndef CUSTOM_DOCKART_H
#define CUSTOM_DOCKART_H

#include <wx/aui/framemanager.h>
#include <wx/aui/aui.h>
#include <wx/aui/dockart.h>
#include <wx/dc.h>
#include <wx/dcclient.h>
#include <wx/brush.h>
#include <iostream>

class Custom_DockArt : public wxAuiDefaultDockArt
{
public:
  Custom_DockArt(){

      this->m_gradientType = wxAUI_GRADIENT_NONE;

      this->m_borderSize = 0;

      this->m_captionSize = 40;

      this->m_buttonSize = 27;

      //this->m_baseColour = wxColour(174, 182, 191);

      this->m_baseColour = wxColour(225,225,225);

      this->m_backgroundBrush.SetColour(this->m_baseColour);

      this->m_sashBrush.SetColour(this->m_baseColour);

      this->m_sashSize = 15;
  }


  void DrawSash(wxDC& dc, wxWindow *window, int orientation, const wxRect& rect)
  {
       dc.SetPen(wxColour(225,225,225));

       dc.SetBrush(wxColour(225,225,225));

       dc.DrawRectangle(rect.x, rect.y, rect.width+5, rect.height+2);
  }

  void DrawBorder(wxDC& dc, wxWindow* window, const wxRect& _rect,
                                    wxAuiPaneInfo& pane)
  {
      dc.SetPen(wxColour(225,225,225));

      dc.SetBrush(wxColour(225,225,225));

      wxRect rect = _rect;

      int i, border_width = GetMetric(wxAUI_DOCKART_PANE_BORDER_SIZE);

      if (pane.IsToolbar())
      {
          for (i = 0; i < border_width+5; ++i)
          {
              dc.SetPen(wxColour(225,225,225));
              dc.DrawLine(rect.x, rect.y, rect.x+rect.width, rect.y);
              dc.DrawLine(rect.x, rect.y, rect.x, rect.y+rect.height);
              dc.SetPen(m_borderPen);
              dc.DrawLine(rect.x, rect.y+rect.height-1,
                          rect.x+rect.width, rect.y+rect.height-1);
              dc.DrawLine(rect.x+rect.width-1, rect.y,
                          rect.x+rect.width-1, rect.y+rect.height);
              rect.Deflate(1);
          }
      }
      else
      {
          // notebooks draw the border themselves, so they can use native rendering (e.g. tabartgtk)
          wxAuiTabArt* art = 0;
          wxAuiNotebook* nb = wxDynamicCast(window, wxAuiNotebook);
          if (nb)
              art = nb->GetArtProvider();

          if (art)
              art->DrawBorder(dc, window, rect);
          else
          {
              for (i = 0; i < border_width; ++i)
              {
                  dc.DrawRectangle(rect.x, rect.y, rect.width, rect.height);
                  rect.Deflate(1);
              }
          }
      }

      window->Refresh();
  }


  void SetColour(int id, const wxColor& colour)
  {

    std::cout << "\n Inside SetColour..";

      wxColor custom_colour = wxColour(225,225,225);

    switch (id)
    {
        case wxAUI_DOCKART_BACKGROUND_COLOUR:                m_backgroundBrush.SetColour(custom_colour); break;
        case wxAUI_DOCKART_SASH_COLOUR:                      m_sashBrush.SetColour(custom_colour); break;
        case wxAUI_DOCKART_INACTIVE_CAPTION_COLOUR:          m_inactiveCaptionColour = custom_colour; break;
        case wxAUI_DOCKART_INACTIVE_CAPTION_GRADIENT_COLOUR: m_inactiveCaptionGradientColour = custom_colour; break;
        case wxAUI_DOCKART_INACTIVE_CAPTION_TEXT_COLOUR:     m_inactiveCaptionTextColour = custom_colour; break;
        case wxAUI_DOCKART_ACTIVE_CAPTION_COLOUR:            m_activeCaptionColour = custom_colour; break;
        case wxAUI_DOCKART_ACTIVE_CAPTION_GRADIENT_COLOUR:   m_activeCaptionGradientColour = custom_colour; break;
        case wxAUI_DOCKART_ACTIVE_CAPTION_TEXT_COLOUR:       m_activeCaptionTextColour = custom_colour; break;
        case wxAUI_DOCKART_BORDER_COLOUR:                    m_borderPen.SetColour(custom_colour); break;
        case wxAUI_DOCKART_GRIPPER_COLOUR:
            m_gripperBrush.SetColour(custom_colour);
            m_gripperPen1.SetColour(custom_colour.ChangeLightness(40));
            m_gripperPen2.SetColour(custom_colour.ChangeLightness(60));
            break;
        default: wxFAIL_MSG(wxT("Invalid Metric Ordinal")); break;
    }

    wxAuiDefaultDockArt::InitBitmaps();

    //InitBitmaps();
}

  void DrawBackground(wxDC& dc, wxWindow *  wnd, const wxRect& _rect) {

    wxRect rect = _rect;

    rect.height = rect.height + 3;

    //dc.SetBrush(wxColour(174, 182, 191));

    dc.SetBrush(wxColour(225,225,225));

    dc.DrawRectangle(rect.GetX()-2, rect.GetY()-2, rect.GetWidth()+5, rect.GetHeight()+5);
  }

  virtual ~Custom_DockArt(){

  }

  wxAuiDefaultDockArt * Clone() {

      return new Custom_DockArt(*this);
  }

  wxBrush * brush_pointer;
};

#endif /* CUSTOM_DOCKART_H */
