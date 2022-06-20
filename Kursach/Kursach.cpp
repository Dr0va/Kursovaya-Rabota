#include <iostream>
#include "choose_menu.h"
#include <windows.h> 
#include <clocale>
#include <locale>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	//system("chcp 1251");
	//OemToCharBuff();
	//BOOL WINAPI SetConsoleOutputCP(866); // установка кодовой страницы в поток вывода
	//BOOL WINAPI SetConsoleCP(866);
	/*COORD coord;
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, &coord);*/
	keybd_event(VK_MENU, 0x38, 0, 0);
	keybd_event(VK_RETURN, 0x1c, 0, 0);
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
	choose_menu();
}
