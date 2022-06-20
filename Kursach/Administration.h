#pragma once
#include <iostream>
#include <string>
#include "func_menu.h"
#include "choose_menu.h"
using namespace std;
class Administration
{
	int No;
	string login;
	string pass;
	int Group = -1;
	Administration* next;
	int temp_ = 0;
public:
	Administration();
	~Administration();
	void DeleteUser(Administration* head);
	void AddNode(Administration* head, int temp_);
	void PrintUser();
};

