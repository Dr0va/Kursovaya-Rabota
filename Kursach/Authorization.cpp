#include <iostream>
#include <stdio.h>
#include <fstream>
#include "choose_menu.h"
#include "Authorization.h"
#include "Registration.h"
#include "choose_login.h"
#include "User.h"
#include "func_menu.h"
#include "Administration.h"
using namespace std;
Authorization::Authorization()
{
}

Authorization::~Authorization()
{
}

void Authorization::WindowAuthorization()
{
	string login, pass, tmpL, tmpP;
	User User_;
	int group_, group;
	ifstream temp_;
	temp_.open("temp.bin");
	temp_ >> group_;
	group = group_;
	temp_.close();
	cout << "АВТОРИЗАЦИЯ\nВведите логин: ";
	cin >> login;
	User_.Setlogin(login);
	cout << "Введите пароль: ";
	cin >> pass;
	User_.Setpass(pass);
	User_.Setgroup(group_);
	ifstream FileAuthorization;
	FileAuthorization.open("Authorization.bin", ios::binary | ios::in);
	if (!FileAuthorization.is_open())
	{
		cout << "Ошибка авторизации! Обратитесь к администратору!\n";
		choose_login();
	}
	while (!FileAuthorization.eof())
	{
		FileAuthorization >> tmpL >> tmpP >> group_;
		if (tmpL == User_.Getlogin() && tmpP == User_.Getpass() && group_ == User_.Getgroup())
		{
			cout << "\nВы успешно авторизировались!\n\n";
			func_menu* Funcmenu = new func_menu();
			FileAuthorization.close();
			system("pause");
			system("cls");
			if (group == 2)
			{
				Administration* Menu = new Administration();
				Menu->PrintUser();
			}
			Funcmenu->FuncMenu();
		}
	}
	FileAuthorization.close();
	cout << "Неверный логин или пароль!\n";
	User_.Setlogin();
	User_.Setpass();
	system("pause");
	system("cls");
	choose_login();
}

