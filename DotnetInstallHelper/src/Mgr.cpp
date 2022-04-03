//Mgr.cpp
#include <iostream>
#include <Windows.h>
void Mgr(LPCSTR exe, LPCSTR param, INT nShow = SW_SHOW)
{
	SHELLEXECUTEINFO sei_mgr;
	sei_mgr.cbSize = sizeof(SHELLEXECUTEINFO);
	sei_mgr.fMask = SEE_MASK_NOCLOSEPROCESS;
	sei_mgr.hInstApp = NULL;
	sei_mgr.hwnd = NULL;
	sei_mgr.lpDirectory = NULL;
	sei_mgr.lpFile = exe;
	sei_mgr.lpParameters = param;
	sei_mgr.lpVerb = "runas";
	sei_mgr.nShow = nShow;
	BOOL ret = ShellExecuteEx(&sei_mgr);
	CloseHandle(sei_mgr.hProcess);
	return;
}