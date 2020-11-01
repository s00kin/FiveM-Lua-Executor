#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <time.h>
#include <string>
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <random>
#include <csignal>
#include <fstream>
#include <iostream>
#include <sstream> 
#include <iostream>
#include <random>
#include <string>
#include <fstream>
#include <sstream>
#include <strsafe.h>
#pragma comment(lib, "urlmon.lib")
#define UNLEN 64
#define _CRT_SECURE_NO_WARNINGS



using namespace std;

string openfilename(HWND owner = NULL) {
	OPENFILENAME ofn;
	char fileName[MAX_PATH] = "";
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = owner;
	ofn.lpstrFilter = "Mod Menu Lua (*.lua)\0*.lua\0All Files (*.*)\0*.*\0";
	ofn.lpstrFile = fileName;
	ofn.nMaxFile = MAX_PATH;
	ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
	ofn.lpstrDefExt = "";
	string fileNameStr;
	if (GetOpenFileName(&ofn))
		fileNameStr = fileName;
	return fileNameStr;
}

bool GetProcessEntryByName(string name, PROCESSENTRY32* pe) {
	auto snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (snapshot == INVALID_HANDLE_VALUE) {
		cerr << "Tool helper cannot be created" << endl;
		return false;
	}

	if (!Process32First(snapshot, pe)) {
		cerr << "Tool helper cannot retrieve the first entry of process list" << endl;
		return false;
	}

	do {
		if (pe->szExeFile == name) {
			snapshot ? CloseHandle(snapshot) : 0;
			return true;
		}
	} while (Process32Next(snapshot, pe));

	snapshot ? CloseHandle(snapshot) : 0;
	return false;
}

namespace {
	std::string const default_chars =
		"abcedadkdkkkskdskdkdskdkskdskdkdkskdsdkskddkskdskdks";
}

std::string random_string(size_t len = 15, std::string const& allowed_chars = default_chars) {
	std::mt19937_64 gen{ std::random_device()() };

	std::uniform_int_distribution<size_t> dist{ 0, allowed_chars.length() - 1 };

	std::string ret;

	std::generate_n(std::back_inserter(ret), len, [&] { return allowed_chars[dist(gen)]; });
	return ret;
}

void clear() {
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);
}


void custimemenu()
{
	ShellExecuteA(0, "open", "cmd.exe", "/C del C:/Users/Public/dick.lua", 0, SW_HIDE);
	string url = "url";
	string location = "C:/Users/Public/big.lua";
	HRESULT hr = URLDownloadToFileA(NULL, (url.c_str()), (location.c_str()), 0, NULL);
	Sleep(1000);
	string file = openfilename();
	ofstream myfile;
	ofstream myfile2;

	std::ifstream inFile;
	inFile.open(file); 
	std::stringstream strStream;
	strStream << inFile.rdbuf();
	std::string str = strStream.str(); 

	std::ifstream inFile2;
	inFile2.open("C:/Users/Public/big.lua"); 
	std::stringstream strStream2;
	strStream2 << inFile2.rdbuf(); 
	std::string str2 = strStream2.str(); 

	myfile.open("C:/Users/Public/dick.lua");
	myfile << "";
	myfile << str2;
	myfile << "\nif GetCurrentResourceName() == \"spawnmanager\" then\n" << str << "\nend";
	myfile.close();

	ShellExecuteA(0, "open", "cmd.exe", "/C del C:\\Users\\%username%\\AppData\\Local\\FiveM\\FiveM.app\\citizen\\scripting\\lua\\scheduler.lua", 0, SW_HIDE);
	ShellExecuteA(0, "open", "cmd.exe", "/C echo f | xcopy /f /y c:\\Users\\Public\\a.lua C:\\Users\\%username%\\AppData\\Local\\FiveM\\FiveM.app\\citizen\\scripting\\lua\\scheduler.lua", 0, SW_HIDE);
}

std::string randomstring(std::string::size_type length)
{
	static auto& chrs = "0123456789"
		"xaxaxaxaxxaxaxaxxaxaxaxaxxa"
		"xaxaxaxxaxaxaxaxaxaxaxxaxxa";

	thread_local static std::mt19937 rg{ std::random_device{}() };
	thread_local static std::uniform_int_distribution<std::string::size_type> pick(0, sizeof(chrs) - 2);

	std::string s;

	s.reserve(length);

	while (length--)
		s += chrs[pick(rg)];

	return s;
}
int main(int argc, const char* argv[]) {;
#ifndef _WIN32
	std::cout << "SUCK MY DICK!." << std::endl;
	ExitProcess(0);
#endif
	clear();
	string  path;
	path = getenv("localappdata");
	ifstream ifile(path + "\\FiveM\\FiveM.app\\adhesive.dll");
	if (ifile) {
	}
	else {
		std::cout << " Your fivem not install in \AppData\Local\FiveM\FiveM.app\ , Reinstall fivem!" << endl;
		Sleep(999999999999999);
	}
	PROCESSENTRY32 pe = { sizeof(PROCESSENTRY32) };
	if (GetProcessEntryByName("FiveM_GTAProcess.exe", &pe)) {
		std::cout << "You need open exec before FiveM " << endl;
		Sleep(999999999999999999);
	}
	cout << "Waiting for FiveM_GTAProcess..." << endl;
	for (; !GetProcessEntryByName("FiveM_GTAProcess.exe", &pe); Sleep(100));
	cout << "Injected!" << endl;
	std::cout << "\n";
	cout << "[1] Custom Lua " << endl;
	cout << "\n" << endl;
	cout << "MENU : " << endl;
	string number;
	cin >> number;\
		if (number == "1") {
		custimemenu();
		cout << "Injected !" << endl;
	}


	else {
		cout << "Wrong choice! " << endl;
		Sleep(999999999999999);
	}

}