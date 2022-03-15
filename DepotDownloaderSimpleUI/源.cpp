#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <io.h>
using namespace std;

void defaultPrompt()
{
	system("cls");
	cout << "Congratulations! You have inputted the information we need." << endl;
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

int main(void)
{
	char TempPath[MAX_PATH] = { 0 };
	GetTempPathA(MAX_PATH, TempPath);//get %temp%
	char AppPath[MAX_PATH] = { 0 };
	GetCurrentDirectoryA(MAX_PATH, AppPath);//get current directory //get existing directory
	if (!_access("C:\\Program Files\\dotnet\\dotnet.exe", 0))//detect if dotnet is installed
	{
		cout << ".NET Environment Detected. Jumping...";
		system("timeout 2 >nul && cls");
	}
	else
	{
		cout << ".NET Environment not available." << endl;
		cout << "We will install .NET Runtime 6.0.3 for you." << endl;
		cout << "Please wait while quiet installing." << endl;
		string installBatchPath = TempPath;
		installBatchPath += "install.bat";
		string installerPath = AppPath;
		if (checkArch() == 4)
		{
			installerPath += "windowsdesktop-runtime-6.0.3-win-x86.exe /q";
		}
		else if (checkArch() == 8)
		{
			installerPath += "windowsdesktop-runtime-6.0.3-win-x64.exe /q";
		}
		ofstream inst;
		inst.open(installBatchPath.c_str());
		inst << "@echo off" << endl;
		cout << endl;
		inst << "start " << installerPath.c_str() << endl;
		inst.close();
		system("%temp\\install.bat");
		system("timeout 1 >nul && del %temp%\\install.bat");
	}
	string outPath = TempPath;
	string DllPath = AppPath;
	outPath += "config.bat";//set bat path
	DllPath += "\\DepotDownloader.dll";//set dll path
	string appid;
	int depotid;
	__int64 manifest, pubfile, ugc;
	string username;
	int looklook;
	while (1)
	{
		system("cls");
		cout << "Welcome! This is a game depot downloader, which download a depot package from Steam servers." << endl;
		cout << "Follow the guide to download any depot packages you want." << endl;
		cout << "All needed IDs can be found on SteamDB." << endl << endl;
		cout << "Please select the working mode." << endl;
		cout << "1. Download one depot for an app" << endl;
		cout << "2. Download a workshop item using pubfile id" << endl;
		cout << "3. Download a workshop item using ugc id" << endl;
		cout << "4. Exit" << endl << endl;
		cout << "Your select:";
		int selection;
		selection = _getch();
		if (selection == 49)
		{
			system("cls");
			cout << "First, input the AppID(Press W to go to SteamDB):";
			char ifSteamDB;
			ifSteamDB = _getch();
			if (ifSteamDB == 119 || ifSteamDB == 87)
			{
				system("start http://steamdb.info");
				cin >> appid;
			}
			else
			{
				string appidTemp;
				appidTemp = char(ifSteamDB); //ASCII transform
				cout << appidTemp;
				string restAppID;
				cin >> restAppID;
				appid = appidTemp + restAppID;
			}
			cout << endl << "Second, the depot ID:";
			cin >> depotid;
			cout << endl << "Then, the manifest ID(This determines the version you want to download):";
			cin >> manifest;
			string dir = "C:\\Depots";
			cout << endl << "Default download location is C:\\Depots" << endl;
			cout << "If it's OK, press Enter" << endl;
			cout << "If you want to change it, Just input new location here:";
			char dirConfirm;
			dirConfirm = _getch();
			if (dirConfirm == '\r') 
			{
				cout << endl;
			}
			else
			{
				string firstDir;
				firstDir = char(dirConfirm);
				cout << firstDir;
				string restDir;
				cin >> restDir;
				dir = firstDir + restDir;
			}
			cout << endl << "Whether the package you want to download is free(0) or paid(1)(input the number):";
			looklook = _getch();
			if (looklook == 48)
			{
				defaultPrompt();
				cout << dir.c_str() << endl;
				ofstream out;
				out.open(outPath.c_str());
				out << "@echo off" << endl;
				cout << endl;
				out << "dotnet \"" << DllPath.c_str() << "\" -app " << appid.c_str() << " -depot " << depotid << " -manifest " << manifest << " -dir " << dir.c_str();
				out.close();
				autoRun();
				break;
			}
			else if (looklook == 49)
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
					else if (ch == '\r')//enter
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
				defaultPrompt();
				cout << dir.c_str() << endl;
				ofstream out;
				out.open(outPath.c_str());
				out << "@echo off" << endl;
				cout << endl;
				out << "dotnet \"" << DllPath.c_str() << "\" -app " << appid.c_str() << " -depot " << depotid << " -manifest " << manifest << " -dir " << dir.c_str() << " -username " << username.c_str() << " -password " << password;
				out.close();
				autoRun();
				break;
			}
		}
		else if (selection == 50)
		{
			system("cls");
			cout << "First, input the AppID:";
			cin >> appid;
			cout << endl << "And the pubfile ID:";
			cin >> pubfile;
			string dir = "C:\\WorkshopItems";
			cout << endl << "Default download location is C:\\WorkshopItems" << endl;
			cout << "If it's OK, press Enter" << endl;
			cout << "If you want to change it, Just input new location here:";
			char dirConfirm;
			dirConfirm = _getch();
			if (dirConfirm == '\r') {}
			else
			{
				string firstDir;
				firstDir = char(dirConfirm);
				cout << firstDir;
				string restDir;
				cin >> restDir;
				dir = firstDir + restDir;
			}
			defaultPrompt();
			cout << dir.c_str() << endl;
			ofstream out;
			out.open(outPath.c_str());
			out << "@echo off" << endl;
			cout << endl;
			out << "dotnet \"" << DllPath.c_str() << "\" -app " << appid.c_str() << " -pubfile " << pubfile << " -dir " << dir.c_str();
			out.close();
			autoRun();
			break;
		}
		else if (selection == 51)
		{
			system("cls");
			cout << "First, input the AppID:";
			cin >> appid;
			cout << endl << "And the UGC ID:";
			cin >> ugc;
			string dir = "C:\\WorkshopItems";
			cout << endl << "Default download location is C:\\WorkshopItems" << endl;
			cout << "If it's OK, press Enter" << endl;
			cout << "If you want to change it, Just input new location here:";
			char dirConfirm;
			dirConfirm = _getch();
			if (dirConfirm == '\r') {}
			else
			{
				string firstDir;
				firstDir = char(dirConfirm);
				cout << firstDir;
				string restDir;
				cin >> restDir;
				dir = firstDir + restDir;
			}
			defaultPrompt();
			cout << dir.c_str() << endl;
			ofstream out;
			out.open(outPath.c_str());
			out << "@echo off" << endl;
			cout << endl;
			out << "dotnet \"" << DllPath.c_str() << "\" -app " << appid.c_str() << " -ugc " << ugc << " -dir " << dir.c_str();
			out.close();
			autoRun();
			break;
		}
		else if (selection == 52)
		{
			break;
		}
		else
		{
			system("cls");
			cout << "Wrong input. Returning." << endl << endl;
			system("timeout 2 >nul && cls");
		}
	}
	return 0;
}