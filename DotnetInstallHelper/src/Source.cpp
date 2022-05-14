#include <iostream>
#include <string>
#include <Windows.h>
#include "../header/exe.hpp"
#include "../header/Mgr.hpp"
#include "../header/arch.hpp"
using namespace std;

int main(int argc, char* argv[])
{
	system("cls");
	cout << "Welcome to .NET installation helper." << endl << endl;
	if (argc == 1)
	{
		cout << "The program needs to be run as Administrator." << endl;
		cout << endl;
		cout << "Checking and restarting..." << endl;
		system("timeout 1 >nul");
		Mgr(argv[0], "2");
		return 0;
	}
	else if (argc == 2)
	{
		cout << "Let's check your system architecture first." << endl << endl;
		system("timeout 1 >nul");
		if (checkArch() == 4)
		{
			cout << "Your system is x86, We are going to install x86 runtime for you." << endl;
			system("timeout 1 >nul && cls");
			cout << "Installing... Please wait.";
			Execute_x86();
		}
		else if (checkArch() == 8)
		{
			cout << "Your system is x64, We are going to install x64 runtime for you." << endl;
			system("timeout 1 >nul && cls");
			cout << "Installing... Please wait." << endl;
			Execute_x64();
		}
		system("cls");
		cout << "Installation has completed, returning to the main program.";
		system("timeout 1 >nul");
		NormalExecute("DepotDownloaderConsoleTool.exe");
	}
	return 0;
}
