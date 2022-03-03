#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <windows.h>
using namespace std;
int main(void)
{
	char TempPath[MAX_PATH] = { 0 };
	GetTempPathA(MAX_PATH, TempPath);//获取temp路径
	string outPath = TempPath;
	outPath += "config.bat";
	char AppPath[MAX_PATH] = { 0 };
	GetCurrentDirectoryA(MAX_PATH, AppPath);//获取当前路径
	string DllPath = AppPath;
	DllPath += "\\DepotDownloader.dll";
	int appid, depotid;
	__int64 manifest;
	string username;
	int looklook;
	cout << "Welcome! This is a game depot downloader, which download a depot package from Steam servers." << endl;
	cout << "Follow the guide to download any depot packages you want.(Exclude workshop)" << endl;
	cout << "All needed IDs can be found on SteamDB." << endl;
	cout << endl << "First, input the AppID:";
	cin >> appid;
	cout << endl <<"Second, the depot ID:";
	cin >> depotid;
	cout << endl << "Then, the manifest ID(This determines the version you want to download):";
	cin >> manifest;
	cout << endl << "Whether the package you want to download is free(0) or paid(1)(input the number):";
	looklook = _getch();
	string dir = "C:\\Depots";
	if (looklook == 48)
	{
		system("cls");
		cout << "Congratulations! You have inputted the information we need." << endl;
		cout << "Default download location is C:\\Depots" << endl;
		cout << "The download is starting and the program will automatically close after the download is completed." << endl;
		ofstream out;
		out.open(outPath.c_str());
		out << "@echo off" << endl;
		cout << endl;
		out << "dotnet \"" << DllPath.c_str() << "\" -app " << appid << " -depot " << depotid << " -manifest " << manifest << " -dir " << dir.c_str();
		out.close();
		system("%temp%\\config.bat");
		system("timeout 1 >nul && del %temp%\\config.bat");
	}
	else if (looklook == 49)
	{
		system("cls");
		cout << "ATTENTION! The account you input must have a license of the paid game. It means that you have already bought the game." << endl;
		cout << endl << "Please input your username:";
		cin >> username;
		cout << username.c_str();
		cout << endl << "And the password:";
		char password[100];
		int index = 0;
		while (1)
		{
			char ch;
			ch = _getch();
			if (ch == 8)
			{
				if (index != 0)
				{
					cout << char(8) << " " << char(8);
					index--;
				}
			}
			else if (ch == '\r')//回车
			{
				password[index] = '\0';
				cout << endl;
				break;
			}
			else
			{
				cout << "*";
				password[index++] = ch;

			}
		}
		system("cls");
		cout << "Congratulations! You have inputted the information we need." << endl;
		cout << "The download is starting and the program will automatically close after the download is completed." << endl;
		ofstream out;
		out.open(outPath.c_str());
		out << "@echo off" << endl;
		cout << endl;
		out << "dotnet \"" << DllPath.c_str() << "\" -app " << appid << " -depot " << depotid << " -manifest " << manifest << " -dir " << dir.c_str() << " -username " << username.c_str() << " -password " << password;
		out.close();
		system("%temp%\\config.bat");
		system("timeout 1 >nul && del %temp%\\config.bat");
	}
	return 0;
}