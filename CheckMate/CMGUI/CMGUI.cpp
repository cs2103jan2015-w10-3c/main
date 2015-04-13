//@author A0118918W
#include "CMGUI.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	CMGUI::CMGUI mainWindow;
	Application::Run(%mainWindow);
	
	return 0;
	
}

