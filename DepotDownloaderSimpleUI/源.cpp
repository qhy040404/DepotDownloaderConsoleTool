#include <iostream>
#include <cstdlib>
#include <fstream>
#include <conio.h>
using namespace std;
int main(void)
{
	char appid, depotid, manifest, username;
	int looklook;
	cout << "Welcome! This is a game depot downloader, which download a depot package from Steam servers." << endl;
	cout << "Follow the guide to download any depot packages you want.(Exclude workshop)" << endl;
	cout << "All needed IDs can be found on SteamDB." << endl;
	cout << endl << "First, input the AppID:";
	cin >> appid;
	cout << endl <<"Second, the depot ID:";
	cin >> depotid;
	cout << endl << "Then, the manifest ID(This determines the version you want to download:";
	cin >> manifest;
	cout << endl << "Whether the package you want to download is free(0) or paid(1)(input the number):";
	cin >> looklook;
	if (looklook == 0)
	{
		system("cls");
		cout << "Congratulations! You have inputted the information we need." << endl;
		cout << "The download is starting and the program will automatically close after the download is completed." << endl;
		ofstream out("config.bat");
		out << "@echo off" << endl;
		cout << endl;
		out << "dotnet DepotDownloader.dll -app " << appid << " -depot " << depotid << " -manifest " << manifest;
		out.close();
		system("config.bat");
		system("timeout 1 >nul && del config.bat");
	}
	else if (looklook == 1)
	{
		system("cls");
		cout << "ATTENTION! The account you input must have a license of the paid game. It means that you have already bought the game." << endl;
		cout << endl << "Please input your username:";
		cin >> username;
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
			else if (ch == '\r')//»Ø³µ
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
		ofstream out("config.bat");
		out << "@echo off" << endl;
		cout << endl;
		out << "dotnet DepotDownloader.dll -app " << appid << " -depot " << depotid << " -manifest " << manifest << " -username " << username << " -password " << password;
		out.close();
		system("config.bat");
		system("timeout 1 >nul && del config.bat");
	}
	return 0;
}