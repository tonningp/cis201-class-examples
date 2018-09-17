#include <wx/wx.h>

/**
   A basic application that shows an empty frame.
*/
class BasicApp : public wxApp
{
public:
   /**
      Constructs and shows the frame.
      @return true
   */
   virtual bool OnInit();
private:
   wxFrame* frame;
};

DECLARE_APP(BasicApp)

IMPLEMENT_APP(BasicApp)

bool BasicApp::OnInit()
{
   frame = new wxFrame(NULL, -1, "My First GUI Program");
   frame->Show(true);
   return true;
}

