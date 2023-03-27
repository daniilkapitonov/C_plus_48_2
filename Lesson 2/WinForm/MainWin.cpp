#include "MainWin.h"

#include <Windows.h>
#include <string.h>
using namespace WinForm;

INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MainWin);
	return 0;
}