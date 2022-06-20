#pragma once
#include <iostream>
#include <string>
#include "User.h"
#include "func_menu.h"
using namespace std;
class PrintDiscipline
{
	struct Discipline
	{
	string name;
	int kurs;
	int priznak;
	int No;
	Discipline* next;
	};
	int temp_ = 0;
public:
	PrintDiscipline();
	~PrintDiscipline();
	void PrintDiscipl();
	void addnode(Discipline* head, int temp_);
};

