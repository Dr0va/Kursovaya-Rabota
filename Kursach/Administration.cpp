#include "Administration.h"
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <fstream>

Administration::Administration()
{
}

Administration::~Administration()
{
}

void Administration::DeleteUser(Administration* k)
{
	cout << "Введите порядковый номер пользователя;\n";
	int choose_, count = 1;
	cin >> choose_;
	Administration* users;
	users = k;
	users = users->next;
	ofstream FileUser_;
	FileUser_.open("Authorization.bin", ios::binary | ios::out);
	while (users != NULL)
	{
		if (count == choose_)
		{
			users = users->next;
			if (users == NULL)
				break;
		}
		FileUser_ << users->login  << " " << users->pass << " " << users->Group;
		if (users->next != NULL)
			FileUser_ << '\n';
		count++;
		users = users->next;
	}
	FileUser_.close();
	system("cls");
	PrintUser();
}

void Administration::PrintUser()
{
	int count_ = 0;
	char* str = new char[1024];
	char smbl;
	ifstream FileUser;
	FileUser.open("Authorization.bin", ios::binary | ios::in);
	if (!FileUser.is_open())
	{
		cout << "Ошибка чтения!\n";
		choose_login();
	}
	while (!FileUser.eof())
	{
		FileUser.getline(str, 1024, '\n');
		smbl = FileUser.get();
		count_++;
	}
	temp_ = count_;
	Administration* k = new Administration;
	k->next = NULL;
	AddNode(k, count_);
	Administration* users = new Administration;
	users = k;
	FileUser.close();
	count_ = 0;
	cout << "№" << "\t|" << setw(20) << left << "Логин" << left << "|" << setw(20) << "Пароль" << "|" << setw(18) << "Роль" << "|" << endl;
	cout << "======================================================================" << endl;
	for (int i = 0; i < temp_; i++)
	{
		count_++;
		users = users->next;
		cout << left << users->No << "\t|" << setw(20) << left << users->login << left << "|" << setw(20) << users->pass << "|";
		if (users->Group == 0)
			cout << setw(18) << "Студент" << "|\n";
		else if (users->Group == 1)
			cout << setw(18) << "Диспетчер" << "|\n";
		else cout << setw(18) << "Администратор" << "|\n";
	}
	int choose;
	int temp = 0;
	cout << "\n\nВыберите действие: \n1) Удаление пользователей;\n2) Назначить диспетчером;\n3) Назначить администратором;\n4) Выйти в меню выбора пользователя;\n5) Выйти из программы;\n\n";
	cin >> choose;
	choose--;
	if (choose == 2) {
		temp = choose;
		choose = 1;
	}
	switch (choose)
	{
	case 0:
	{
		DeleteUser(k);
	}
	case 1:
	{
		if (temp == 2)
			choose = 2;
		cout << "Введите порядковый номер пользователя;\n";
		int choose_;
		cin >> choose_;
		users = k;
		while (users->next != NULL)
		{
			users = users->next;
			if (choose_ == users->No)
			{
				users->Group = choose;
				break;
			}
		}
		ifstream FileUser;
		ofstream FileUser_;
		FileUser.open("Authorization.bin", ios::binary | ios::in);
		FileUser_.open("Authorization.bin", ios::binary | ios::out);
		Administration* left_ = new Administration;
		left_ = k;
		while (left_->next != NULL)
		{
			left_ = left_->next;
			FileUser >> left_->login >> left_->pass >> left_->Group;
			if (left_->login == users->login)
			{
				left_->Group = choose;
			}
			FileUser_ << left_->login << " " << left_->pass << " " << left_->Group;
			if (left_->next != NULL)
			{
				FileUser_ << "\n";
			}
		}
		FileUser.close();
		FileUser_.close();
		system("cls");
		PrintUser();
	}
	case 3:
	{
		system("cls");
		choose_menu();
	}
	case 4:
	{
		remove("temp.bin");
		exit(0);
	}
	default:
		system("cls");
		cout << "Ошибка ввода!\n";
		system("pause");
		system("cls");
		PrintUser();
	}
}

void Administration::AddNode(Administration* head, int temp_)
{
	ifstream FileStudents;
	int i = 0, count = 0;
	string temp;
	FileStudents.open("Authorization.bin", ios::binary | ios::in);
	for (i; i < temp_; i++)
	{
		count++;
		Administration* users = head;
		while (users->next != NULL)
			users = users->next;
		Administration* new_node = new Administration;
		new_node->next = NULL;
		FileStudents >> new_node->login >> new_node->pass >> new_node->Group;
		if (new_node->Group == -1)
			break;
		new_node->No = count;
		users->next = new_node;
	}
}

