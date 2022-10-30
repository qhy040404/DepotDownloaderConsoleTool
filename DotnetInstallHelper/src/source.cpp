#include <iostream>
#include <string>
#include <Windows.h>
#include "../header/exe.hpp"
#include "../header/Mgr.hpp"
#include "../header/arch.hpp"

int main(int argc, char* argv[])
{
	system("cls");
	std::cout << "Welcome to .NET installation helper." << std::endl << std::endl;
	if (argc == 1)
	{
		std::cout << "The program needs to be run as Administrator." << std::endl;
		std::cout << std::endl;
		std::cout << "Checking and restarting..." << std::endl;
		system("timeout 1 >nul");
		Mgr(argv[0], "2");
		return 0;
	}
	else if (argc == 2)
	{
		std::cout << "Let's check your system architecture first." << std::endl << std::endl;
		system("timeout 1 >nul");
		if (checkArch() == 4)
		{
			std::cout << "Your system is x86, We are going to install x86 runtime for you." << std::endl;
			system("timeout 1 >nul && cls");
			std::cout << "Installing... Please wait.";
			Execute_x86();
		}
		else if (checkArch() == 8)
		{
			std::cout << "Your system is x64, We are going to install x64 runtime for you." << std::endl;
			system("timeout 1 >nul && cls");
			std::cout << "Installing... Please wait." << std::endl;
			Execute_x64();
		}
		system("cls");
		std::cout << "Installation has completed, returning to the main program.";
		system("timeout 1 >nul");
		NormalExecute("DepotDownloaderConsoleTool.exe");
	}
	return 0;
}
