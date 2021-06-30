#ifndef CHATGUI_H_
#define CHATGUI_H_

#include <memory>
#include <string>

#include <wx/wx.h>
#include <wx/colour.h>
#include <wx/filename.h>
#include <wx/image.h>

#include "chatbot.h"
#include "chatlogic.h"

class ChatLogic; // forward declaration

// middle part of the window containing the dialog between user and chatbot
class ChatBotPanelDialog : public wxScrolledWindow {
private:
  // control elements
  wxBoxSizer *_dialogSizer;
  wxBitmap _image;

  //// STUDENT CODE
  ////

  std::unique_ptr<ChatLogic> _chatLogic;

  ////
  //// EOF STUDENT CODE

public:
  // constructor / destructor
  ChatBotPanelDialog(wxWindow *parent, wxWindowID id);
  ~ChatBotPanelDialog();

  // getter / setter
  ChatLogic *GetChatLogicHandle() { return _chatLogic.get(); }

  // events
  void paintEvent(wxPaintEvent &evt);
  void paintNow();
  void render(wxDC &dc);

  // proprietary functions
  void AddDialogItem(wxString text, bool isFromUser = true);
  void PrintChatbotResponse(std::string response);
};

// dialog item shown in ChatBotPanelDialog
class ChatBotPanelDialogItem : public wxPanel {
private:
  // control elements
  wxStaticBitmap *_chatBotImg;
  wxStaticText *_chatBotTxt;

public:
  // constructor / destructor
  ChatBotPanelDialogItem(wxPanel *parent, wxString text, bool isFromUser);
  ~ChatBotPanelDialogItem(){};
};

// frame containing all control elements
class ChatBotFrame : public wxFrame {
private:
  // control elements
  ChatBotPanelDialog *_panelDialog;
  wxTextCtrl *_userTextCtrl;

  // events
  void OnEnter(wxCommandEvent &WXUNUSED(event));

public:
  // constructor / desctructor
  ChatBotFrame(const wxString &title);
  ~ChatBotFrame(){};
};

// control panel for background image display
class ChatBotFrameImagePanel : public wxPanel {
  // control elements
  wxBitmap _image;
  bool _image_is_loaded = false;

public:
  // constructor / desctructor
  ChatBotFrameImagePanel(wxFrame *parent);
  ~ChatBotFrameImagePanel(){};
  // events
  void paintEvent(wxPaintEvent &evt);
  void paintNow();
  void render(wxDC &dc);
};

// wxWidgets app that hides main()
class ChatBotApp : public wxApp {
public:
  // events
  virtual bool OnInit();
  ~ChatBotApp(){};
};

#endif /* CHATGUI_H_ */
