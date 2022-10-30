//exe.hpp
//
#include <iostream>
#include <string>
#include <Windows.h>

void Execute_x86()
{
	const char appname[MAX_PATH] = "rumtime-x86.exe";
	char path[MAX_PATH] = " /q";
	STARTUPINFO si_x86;
	PROCESS_INFORMATION pi_x86;

	ZeroMemory(&si_x86, sizeof(si_x86));
	si_x86.cb = sizeof(si_x86);
	ZeroMemory(&pi_x86, sizeof(pi_x86));

	CreateProcess(appname, path, NULL, NULL, FALSE, 0, NULL, NULL, &si_x86, &pi_x86);

	WaitForSingleObject(pi_x86.hProcess, INFINITE);

	CloseHandle(pi_x86.hProcess);
	CloseHandle(pi_x86.hThread);

	return;
}

void Execute_x64()
{
	const char appname[MAX_PATH] = "runtime-x64.exe";
	char path[MAX_PATH] = " /q";
	STARTUPINFO si_x64;
	PROCESS_INFORMATION pi_x64;

	ZeroMemory(&si_x64, sizeof(si_x64));
	si_x64.cb = sizeof(si_x64);
	ZeroMemory(&pi_x64, sizeof(pi_x64));

	CreateProcess(appname, path, NULL, NULL, FALSE, 0, NULL, NULL, &si_x64, &pi_x64);

	WaitForSingleObject(pi_x64.hProcess, INFINITE);

	CloseHandle(pi_x64.hProcess);
	CloseHandle(pi_x64.hThread);

	return;
}

void NormalExecute(LPCSTR exe, INT nShow = SW_SHOW)
{
	SHELLEXECUTEINFO ShExecInfo;
	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	ShExecInfo.hwnd = NULL;
	ShExecInfo.lpVerb = "open";
	ShExecInfo.lpFile = exe;
	ShExecInfo.lpParameters = NULL;
	ShExecInfo.lpDirectory = NULL;
	ShExecInfo.nShow = nShow;
	ShExecInfo.hInstApp = NULL;
	BOOL ret = ShellExecuteEx(&ShExecInfo);
	CloseHandle(ShExecInfo.hProcess);
	return;
}