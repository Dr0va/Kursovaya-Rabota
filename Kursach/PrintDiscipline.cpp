#include "PrintDiscipline.h"
#include "func_menu.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include "choose_menu.h"
#include "Authorization.h"
#include "Registration.h"
#include "choose_login.h"
#include "User.h"
PrintDiscipline::PrintDiscipline()
{
}

PrintDiscipline::~PrintDiscipline()
{
}

void PrintDiscipline::PrintDiscipl()
{
	string temp;
	ifstream tmp;
	int count_ = 0;
	tmp.open("temp.bin");
	int i = 0, group_;
	tmp >> group_;
	tmp.close();
	char* str = new char[1024];
	ifstream FileDiscipline;
	FileDiscipline.open("Discipline.bin", ios::binary | ios::in);
	if (!FileDiscipline.is_open())
	{
		cout << "Ошибка чтения! Обратитесь к администратору!\n";
		func_menu* Menu = new func_menu();
		Menu->FuncMenu();
	}
	while (!FileDiscipline.eof())
	{
		FileDiscipline.getline(str, 1024, '\n');
		count_++;
	}
	temp_ = count_;
	Discipline* k = new Discipline;
	k->next = NULL;
	addnode(k, count_);
	Discipline* current = new Discipline;
	current = k;
	FileDiscipline.close();
	int count = 0;
	cout << "№" << "\t|" << left << setw(25) << "Название дисциплины" << "|" << setw(13) << "Курс" << "|" << setw(25) << "Признак зачёта/экзамена" << "|" << endl;
	cout << "===========================================================================" << endl;
	for (int i = 0; i < temp_; i++)
	{
		count++;
		current = current->next;
		cout << count << "\t|" << setw(25) << left << current->name << left << "|" << current->kurs << " курс" << "\t|";
		if (current->priznak == 0)
			cout << setw(25) << "Зачёт" << "|";
		else cout << setw(25) << "Экзамен" << "|";
		cout << "\n";
	}
	current = k;
	count = 0;
	int choose;
	cout << "\n\n1) Вывод дисциплин по выбранному курсу;\n2) Выйти в меню функций;\n3) Выйти в меню выбора пользователя;\n4) Выйти из программы;\n\n";
	cin >> choose;
	choose--;
	switch (choose)
	{
	case 0:
	{
		cout << "Введите номер курса:\n";
		int choise;
		cin >> choise;
		system("cls");
		cout << "№" << "\t|" << left << setw(25) << "Название дисциплины" << "|" << setw(13) << "Курс" << "|" << setw(25) << "Признак зачёта/экзамена" << "|" << endl;
		cout << "===========================================================================" << endl;
		for (int i = 0; i < temp_; i++)
		{
			current = current->next;
			if (choise == current->kurs) {
				count++;
				cout << count << "\t|" << setw(25) << left << current->name << left << "|" << current->kurs << " курс" << "\t|";
				if (current->priznak == 0)
					cout << setw(25) << "Зачёт" << "|";
				else cout << setw(25) << "Экзамен" << "|";
				cout << "\n";
			}
		}
		if (count == 0)
			cout << "Дисциплин выбранного курса нет!\n";
		system("pause");
		system("cls");
		PrintDiscipl();
	}
	case 1:
	{
		system("cls");
		func_menu* Menu = new func_menu;
		Menu->FuncMenu();
	}
	case 2:
	{
		system("cls");
		choose_menu();
	}
	case 3:
	{
		remove("temp.bin");
		exit(0);
	}
	default:
		cout << "Ошибка!\n";
		system("pause");
		system("cls");
		PrintDiscipl();
	}
}

void PrintDiscipline::addnode(Discipline* head, int temp_)
{
	ifstream FileDiscipline;
	int i = 0;
	FileDiscipline.open("Discipline.bin", ios::binary | ios::in);
	for (i; i < temp_; i++)
	{
		Discipline* current = head;
		while (current->next != NULL)
			current = current->next;
		Discipline* new_node = new Discipline;
		new_node->next = NULL;
		FileDiscipline >> new_node->name >> new_node->kurs >> new_node->priznak;
		current->next = new_node;
	}
	FileDiscipline.close();
}
