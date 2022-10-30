#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <io.h>
#include "../header/func_ez.hpp"
#include "../header/exe.hpp"

int main(void)
{
	char TempPath[MAX_PATH] = { 0 };
	GetTempPathA(MAX_PATH, TempPath);//get %temp%
	char AppPath[MAX_PATH] = { 0 };
	GetCurrentDirectoryA(MAX_PATH, AppPath);//get current directory //get existing directory
	if (!_access("C:\\Program Files\\dotnet\\dotnet.exe", 0))//detect if dotnet is installed
	{
		std::cout << ".NET Environment Detected. Jumping...";
		system("timeout 2 >nul && cls");
	}
	else
	{
		std::cout << ".NET Environment not available." << std::endl;
		if (checkVer()) 
		{
			std::cout << "Starting .NET installation helper..." << std::endl;
			system("timeout 1 >nul");
			Execute("DotnetInstallHelper.exe");
			exit(0);
		}
		else
		{
			std::cout << "This version doesn't include .NET installer." << std::endl;
			std::cout << "Please go to https://dotnet.microsoft.com/download/dotnet to download .NET Runtime and install manually." << std::endl;
			std::cout << "Press any key to exit.";
			system("pause >nul");
			exit(0);
		}
	}
	std::string outPath = TempPath;
	std::string DllPath = AppPath;
	outPath += "config.bat";//set bat path
	DllPath += "\\DepotDownloader.dll";//set dll path
	std::string appid;
	int depotid;
	__int64 manifest, pubfile, ugc;
	std::string username;
	int looklook;
	while (1)
	{
		system("cls");
		std::cout << "Welcome! This is a game depot downloader, which download a depot package from Steam servers." << std::endl;
		std::cout << "Follow the guide to download any depot packages you want." << std::endl;
		std::cout << "All needed IDs can be found on SteamDB." << std::endl << std::endl;
		std::cout << "Please select the working mode." << std::endl;
		std::cout << "1. Download one depot for an app" << std::endl;
		std::cout << "2. Download a workshop item using pubfile id" << std::endl;
		std::cout << "3. Download a workshop item using ugc id" << std::endl;
		std::cout << "4. Exit" << std::endl << std::endl;
		std::cout << "Your select:";
		int selection;
		selection = _getch();
		if (selection == 49)
		{
			system("cls");
			std::cout << "First, input the AppID(Press W to go to SteamDB):";
			char ifSteamDB;
			ifSteamDB = _getch();
			if (ifSteamDB == 119 || ifSteamDB == 87)
			{
				system("start http://steamdb.info");
				std::cin >> appid;
			}
			else
			{
				std::string appidTemp;
				appidTemp = char(ifSteamDB); //ASCII transform
				std::cout << appidTemp;
				std::string restAppID;
				std::cin >> restAppID;
				appid = appidTemp + restAppID;
			}
			std::cout << std::endl << "Second, the depot ID:";
			std::cin >> depotid;
			std::cout << std::endl << "Then, the manifest ID(This determines the version you want to download):";
			std::cin >> manifest;
			std::string dir = "C:\\Depots";
			std::cout << std::endl << "Default download location is C:\\Depots" << std::endl;
			std::cout << "If it's OK, press Enter" << std::endl;
			std::cout << "If you want to change it, Just input new location here:";
			char dirConfirm;
			dirConfirm = _getch();
			if (dirConfirm == '\r')
			{
				std::cout << std::endl;
			}
			else
			{
				std::string firstDir;
				firstDir = char(dirConfirm);
				std::cout << firstDir;
				std::string restDir;
				std::cin >> restDir;
				dir = firstDir + restDir;
			}
			std::cout << std::endl << "Whether the package you want to download is free(0) or paid(1)(input the number):";
			looklook = _getch();
			if (looklook == 48)
			{
				defaultPrompt();
				std::cout << dir.c_str() << std::endl;
				std::ofstream out;
				out.open(outPath.c_str());
				out << "@echo off" << std::endl;
				std::cout << std::endl;
				out << "dotnet \"" << DllPath.c_str() << "\" -app " << appid.c_str() << " -depot " << depotid << " -manifest " << manifest << " -dir " << dir.c_str();
				out.close();
				autoRun();
				break;
			}
			else if (looklook == 49)
			{
				system("cls");
				std::cout << "ATTENTION! The account you input must have a license of the paid game. It means that you have already bought the game." << std::endl;
				std::cout << std::endl << "Please input your username:";
				std::cin >> username;
				std::cout << std::endl << "And the password:";
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
							std::cout << char(8) << " " << char(8);
							index--;
						}
					}
					else if (ch == '\r')//enter
					{
						password[index] = '\0';
						std::cout << std::endl;
						break;
					}
					else
					{
						std::cout << "*";
						password[index++] = ch;
					}
				}
				defaultPrompt();
				std::cout << dir.c_str() << std::endl;
				std::ofstream out;
				out.open(outPath.c_str());
				out << "@echo off" << std::endl;
				std::cout << std::endl;
				out << "dotnet \"" << DllPath.c_str() << "\" -app " << appid.c_str() << " -depot " << depotid << " -manifest " << manifest << " -dir " << dir.c_str() << " -username " << username.c_str() << " -password " << password;
				out.close();
				autoRun();
				break;
			}
		}
		else if (selection == 50)
		{
			system("cls");
			std::cout << "First, input the AppID:";
			std::cin >> appid;
			std::cout << std::endl << "And the pubfile ID:";
			std::cin >> pubfile;
			std::string dir = "C:\\WorkshopItems";
			std::cout << std::endl << "Default download location is C:\\WorkshopItems" << std::endl;
			std::cout << "If it's OK, press Enter" << std::endl;
			std::cout << "If you want to change it, Just input new location here:";
			char dirConfirm;
			dirConfirm = _getch();
			if (dirConfirm == '\r') {}
			else
			{
				std::string firstDir;
				firstDir = char(dirConfirm);
				std::cout << firstDir;
				std::string restDir;
				std::cin >> restDir;
				dir = firstDir + restDir;
			}
			defaultPrompt();
			std::cout << dir.c_str() << std::endl;
			std::ofstream out;
			out.open(outPath.c_str());
			out << "@echo off" << std::endl;
			std::cout << std::endl;
			out << "dotnet \"" << DllPath.c_str() << "\" -app " << appid.c_str() << " -pubfile " << pubfile << " -dir " << dir.c_str();
			out.close();
			autoRun();
			break;
		}
		else if (selection == 51)
		{
			system("cls");
			std::cout << "First, input the AppID:";
			std::cin >> appid;
			std::cout << std::endl << "And the UGC ID:";
			std::cin >> ugc;
			std::string dir = "C:\\WorkshopItems";
			std::cout << std::endl << "Default download location is C:\\WorkshopItems" << std::endl;
			std::cout << "If it's OK, press Enter" << std::endl;
			std::cout << "If you want to change it, Just input new location here:";
			char dirConfirm;
			dirConfirm = _getch();
			if (dirConfirm == '\r') {}
			else
			{
				std::string firstDir;
				firstDir = char(dirConfirm);
				std::cout << firstDir;
				std::string restDir;
				std::cin >> restDir;
				dir = firstDir + restDir;
			}
			defaultPrompt();
			std::cout << dir.c_str() << std::endl;
			std::ofstream out;
			out.open(outPath.c_str());
			out << "@echo off" << std::endl;
			std::cout << std::endl;
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
			std::cout << "Wrong input. Returning." << std::endl << std::endl;
			system("timeout 2 >nul && cls");
		}
	}
	return 0;
}