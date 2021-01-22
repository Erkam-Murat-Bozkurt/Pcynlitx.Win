/*

Copyright ©  2021,  Erkam Murat Bozkurt

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

#include "Style_Loader.h"

Style_Loader::Style_Loader(){

}

Style_Loader::~Style_Loader(){

}

void Style_Loader::Set_Lexer_Style(wxFont Default_Font, wxStyledTextCtrl * text_ctrl){

     text_ctrl->StyleClearAll();

     this->Set_Margin_Style(text_ctrl);

     text_ctrl->SetLexer(wxSTC_LEX_CPP);

     text_ctrl->SetCaretForeground(wxColour(70,70,70));

     text_ctrl->SetCaretWidth(2);

     this->Set_Style_Font(Default_Font,text_ctrl);

     text_ctrl->StyleSetForeground(wxSTC_C_STRING,wxColour(0, 128, 128));

     text_ctrl->StyleSetForeground(wxSTC_C_PREPROCESSOR,wxColour(205, 92, 92));

     text_ctrl->StyleSetForeground(wxSTC_C_IDENTIFIER,wxColour(25,25,25));

     text_ctrl->StyleSetForeground(wxSTC_C_NUMBER,wxColour(160,76,0));

     text_ctrl->StyleSetForeground(wxSTC_C_CHARACTER,wxColour(150,0,0));

     text_ctrl->StyleSetForeground(wxSTC_C_OPERATOR,wxColour(90,90,90));

     text_ctrl->StyleSetForeground(wxSTC_C_WORD,wxColour(41, 128, 185));

     text_ctrl->StyleSetForeground(wxSTC_C_WORD2,wxColour(41, 128, 185));

     text_ctrl->StyleSetForeground(wxSTC_C_COMMENT,wxColour(150,150,150));

     text_ctrl->StyleSetForeground(wxSTC_C_COMMENTLINE,wxColour(150,150,150));

     text_ctrl->StyleSetForeground(wxSTC_C_COMMENTDOC,wxColour(150,150,150));

     text_ctrl->StyleSetForeground(wxSTC_C_COMMENTDOCKEYWORD,wxColour(150,150,150));

     text_ctrl->StyleSetForeground(wxSTC_C_COMMENTDOCKEYWORDERROR,wxColour(150,150,150));

     text_ctrl->StyleSetForeground(wxSTC_C_COMMENTLINEDOC,wxColour(150,150,150));

     text_ctrl->StyleSetForeground(wxSTC_C_DEFAULT,wxColour(41, 128, 185));

     text_ctrl->StyleSetForeground(wxSTC_C_REGEX,wxColour(90,90,90));

     text_ctrl->StyleSetForeground(wxSTC_C_HASHQUOTEDSTRING,wxColour(25,25,25));

     text_ctrl->StyleSetForeground(wxSTC_C_STRINGEOL,wxColour(25,25,25));

     text_ctrl->StyleSetForeground(wxSTC_C_UUID,wxColour(25,25,25));

     text_ctrl->StyleSetForeground(wxSTC_C_VERBATIM,wxColour(25,25,25));


     text_ctrl->StyleSetBackground(wxSTC_C_COMMENT,wxColour(255, 255, 255));

     text_ctrl->StyleSetBackground(wxSTC_C_COMMENTLINE,wxColour(255, 255, 255));

     text_ctrl->StyleSetBackground(wxSTC_C_COMMENTDOC,wxColour(255, 255, 255));

     text_ctrl->StyleSetBackground(wxSTC_C_COMMENTDOCKEYWORD, wxColour(255, 255, 255));

     text_ctrl->StyleSetBackground(wxSTC_C_COMMENTDOCKEYWORDERROR, wxColour(255, 255, 255));

     text_ctrl->StyleSetBackground(wxSTC_C_COMMENTLINEDOC, wxColour(255, 255, 255));

     text_ctrl->StyleSetBackground(wxSTC_C_CHARACTER,wxColour(255, 255, 255));

     text_ctrl->StyleSetBackground(wxSTC_C_DEFAULT,wxColour(255, 255, 255));

     text_ctrl->StyleSetBackground(wxSTC_C_IDENTIFIER,wxColour(255, 255, 255));

     text_ctrl->StyleSetBackground(wxSTC_C_NUMBER,wxColour(255, 255, 255));

     text_ctrl->StyleSetBackground(wxSTC_C_OPERATOR,wxColour(255, 255, 255));

     text_ctrl->StyleSetBackground(wxSTC_C_PREPROCESSOR,wxColour(255, 255, 255));

     text_ctrl->StyleSetBackground(wxSTC_C_REGEX,wxColour(255, 255, 255));

     text_ctrl->StyleSetBackground(wxSTC_C_STRING,wxColour(255, 255, 255));

     text_ctrl->StyleSetBackground(wxSTC_C_STRINGEOL,wxColour(255, 255, 255));

     text_ctrl->StyleSetBackground(wxSTC_C_UUID,wxColour(255, 255, 255));

     text_ctrl->StyleSetBackground(wxSTC_C_VERBATIM,wxColour(255, 255, 255));

     text_ctrl->StyleSetBackground(wxSTC_C_WORD,wxColour(255, 255, 255));

     text_ctrl->StyleSetBackground(wxSTC_C_WORD2,wxColour(255, 255, 255));


     text_ctrl->StyleSetBold(wxSTC_C_OPERATOR,false);

     text_ctrl->StyleSetBold(wxSTC_C_CHARACTER,false);

     text_ctrl->StyleSetBold(wxSTC_C_PREPROCESSOR,false);

     text_ctrl->StyleSetBold(wxSTC_C_WORD,false);

     text_ctrl->StyleSetBold(wxSTC_C_WORD2,false);

     text_ctrl->StyleSetBold(wxSTC_C_COMMENTDOCKEYWORD,false);

     text_ctrl->StyleSetBold(wxSTC_C_COMMENTDOCKEYWORDERROR,false);

     text_ctrl->StyleSetBold(wxSTC_C_COMMENT,false);

     text_ctrl->StyleSetBold(wxSTC_C_COMMENTDOC,false);

     text_ctrl->StyleSetBold(wxSTC_C_COMMENTLINE,false);

     text_ctrl->StyleSetBold(wxSTC_C_COMMENTLINEDOC,false);

     text_ctrl->StyleSetBold(wxSTC_C_DEFAULT,false);

     text_ctrl->StyleSetBold(wxSTC_C_REGEX,false);

     text_ctrl->StyleSetBold(wxSTC_C_HASHQUOTEDSTRING,false);

     text_ctrl->StyleSetBold(wxSTC_C_IDENTIFIER,false);

     text_ctrl->StyleSetBold(wxSTC_C_NUMBER,false);

     text_ctrl->StyleSetBold(wxSTC_C_STRING,false);

     text_ctrl->StyleSetBold(wxSTC_C_STRINGEOL,false);

     text_ctrl->StyleSetBold(wxSTC_C_UUID,false);

     text_ctrl->StyleSetBold(wxSTC_C_VERBATIM,false);

     text_ctrl->SetModEventMask(wxSTC_MOD_INSERTTEXT | wxSTC_MOD_DELETETEXT | wxSTC_MOD_CHANGESTYLE);

     text_ctrl->SetKeyWords(0, wxT("return int char this new if else for while void class float double Description virtual delete long bool sem_t"));

     text_ctrl->SetKeyWords(1, wxT("public private protected break PROCESS DESCRIPTOR FILE"));

     text_ctrl->SetUseTabs(false);

     text_ctrl->SetFocus();

     text_ctrl->SetOvertype(false);

     text_ctrl->SetUndoCollection(true);

     text_ctrl->BeginUndoAction();
}

void Style_Loader::Set_Style_Font(wxFont Font, wxStyledTextCtrl * text_ctrl){

     text_ctrl->StyleSetFont(wxSTC_C_STRING,Font);

     text_ctrl->StyleSetFont(wxSTC_C_PREPROCESSOR,Font);

     text_ctrl->StyleSetFont(wxSTC_C_IDENTIFIER,Font);

     text_ctrl->StyleSetFont(wxSTC_C_NUMBER,Font);

     text_ctrl->StyleSetFont(wxSTC_C_OPERATOR,Font);

     text_ctrl->StyleSetFont(wxSTC_C_CHARACTER,Font);

     text_ctrl->StyleSetFont(wxSTC_C_WORD,Font);

     text_ctrl->StyleSetFont(wxSTC_C_WORD2,Font);

     text_ctrl->StyleSetFont(wxSTC_C_COMMENT,Font);

     text_ctrl->StyleSetFont(wxSTC_C_COMMENTLINE,Font);

     text_ctrl->StyleSetFont(wxSTC_C_COMMENTDOC,Font);

     text_ctrl->StyleSetFont(wxSTC_C_COMMENTLINEDOC,Font);

     text_ctrl->StyleSetFont(wxSTC_C_COMMENTDOCKEYWORD,Font);

     text_ctrl->StyleSetFont(wxSTC_C_COMMENTDOCKEYWORDERROR,Font);

     text_ctrl->StyleSetFont(wxSTC_C_DEFAULT,Font);

     text_ctrl->StyleSetFont(wxSTC_C_REGEX,Font);

     text_ctrl->StyleSetFont(wxSTC_C_HASHQUOTEDSTRING,Font);

     text_ctrl->StyleSetFont(wxSTC_C_STRINGEOL,Font);

     text_ctrl->StyleSetFont(wxSTC_C_UUID,Font);

     text_ctrl->StyleSetFont(wxSTC_C_VERBATIM,Font);
}

void Style_Loader::Set_Margin_Style(wxStyledTextCtrl * text_ctrl){

     text_ctrl->SetMarginWidth(MARGIN_LINE_NUMBERS,40);

     text_ctrl->StyleSetForeground(wxSTC_STYLE_LINENUMBER,wxColour(95,95,95));

     text_ctrl->StyleSetBackground(wxSTC_STYLE_LINENUMBER,wxColour(220,220,220));

     text_ctrl->SetMarginType(MARGIN_LINE_NUMBERS,wxSTC_MARGIN_NUMBER);

     text_ctrl->SetMarginSensitive(MARGIN_LINE_NUMBERS,false);

     text_ctrl->SetMarginCursor(MARGIN_LINE_NUMBERS,0);

     // ---- Enable code folding



     text_ctrl->SetMarginType(MARGIN_FOLD, wxSTC_MARGIN_SYMBOL);

     text_ctrl->SetMarginWidth(MARGIN_FOLD,15);

     text_ctrl->SetMarginMask (MARGIN_FOLD, wxSTC_MASK_FOLDERS);



     text_ctrl->StyleSetBackground(MARGIN_FOLD,wxColor(200,200,200));

     text_ctrl->SetMarginSensitive(MARGIN_FOLD, false);

     text_ctrl->SetMarginCursor(MARGIN_FOLD,0);


}

void Style_Loader::Clear_Text_Control_Style(wxStyledTextCtrl * text_ctrl, wxFont Default_Font){

       text_ctrl->StyleClearAll();

       this->Set_Margin_Style(text_ctrl);

       this->Set_Style_Font(Default_Font,text_ctrl);
}

void Style_Loader::Reload_Text_Control_Style(wxStyledTextCtrl * text_ctrl, wxFont Default_Font){

       this->Set_Margin_Style(text_ctrl);

       this->Set_Lexer_Style(Default_Font,text_ctrl);
}

void Style_Loader::Use_Bold_Styling(wxStyledTextCtrl * text_ctrl){

     text_ctrl->StyleSetBold(wxSTC_C_CHARACTER,false);

     text_ctrl->StyleSetBold(wxSTC_C_PREPROCESSOR,true);

     text_ctrl->StyleSetBold(wxSTC_C_WORD,true);

     text_ctrl->StyleSetBold(wxSTC_C_WORD2,true);

     text_ctrl->StyleSetBold(wxSTC_C_IDENTIFIER,false);

     text_ctrl->StyleSetBold(wxSTC_C_NUMBER,true);

     text_ctrl->StyleSetBold(wxSTC_C_STRING,true);

     text_ctrl->StyleSetBold(wxSTC_C_STRINGEOL,true);

     text_ctrl->StyleSetBold(wxSTC_C_OPERATOR,false);

     text_ctrl->StyleSetBold(wxSTC_C_REGEX,false);

     text_ctrl->StyleSetBold(wxSTC_C_DEFAULT,false);

     text_ctrl->StyleSetBold(wxSTC_C_COMMENTDOCKEYWORD,false);

     text_ctrl->StyleSetBold(wxSTC_C_COMMENTDOCKEYWORDERROR,false);

     text_ctrl->StyleSetBold(wxSTC_C_COMMENT,false);

     text_ctrl->StyleSetBold(wxSTC_C_COMMENTDOC,false);

     text_ctrl->StyleSetBold(wxSTC_C_COMMENTLINE,false);

     text_ctrl->StyleSetBold(wxSTC_C_COMMENTLINEDOC,false);

     text_ctrl->StyleSetBold(wxSTC_C_UUID,false);

     text_ctrl->StyleSetBold(wxSTC_C_VERBATIM,false);
}
