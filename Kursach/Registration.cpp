#include <iostream>
#include <stdio.h>
#include <fstream>
#include "choose_menu.h"
#include "Registration.h"
#include "choose_login.h"

using namespace std;
Registration::Registration()
{
}

Registration::~Registration()
{
}

void Registration::WindowRegistration()
{
	string login, pass, tmpL, tmpP;
	User User_;
	int group_;
	ifstream temp_;
	temp_.open("temp.bin");
	temp_ >> group_;
	temp_.close();
	cout << "�����������:\n������� �����: ";
	cin >> login;
	User_.Setlogin(login);
	cout << "������� ������: ";
	cin >> pass;
	User_.Setpass(pass);
	User_.Setgroup(group_);
	ofstream FileRegistration;
	ifstream FileAuthorization;
	FileAuthorization.open("Authorization.bin", ios::binary | ios::in);
	FileRegistration.open("Authorization.bin", ios::app | ios::binary | ios::out);
	if (!FileAuthorization.is_open())
	{
		cout << "������ �����������! ���������� � ��������������!\n";
		choose_login();
	}
	while (!FileAuthorization.eof())
	{
		FileAuthorization >> tmpL >> tmpP >> group_;
		if (tmpL == User_.Getlogin())
		{
			cout << "����� ������������ ��� ����������!\n";
			FileAuthorization.close();
			FileRegistration.close();
			User_.Setlogin();
			User_.Setpass();
			system("pause");
			system("cls");
			choose_login();
		}
	}
	FileRegistration << User_.Getlogin() << ' ' << User_.Getpass() << ' ' << User_.Getgroup() << "\n";
	FileRegistration.close();
	FileAuthorization.close();
	cout << "����������� ������ �������!\n";
	system("pause");
	system("cls");
	choose_login();
}