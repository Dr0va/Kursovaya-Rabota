#pragma once
#include <string>
#include <iostream>
using namespace std;

class User
{
	string login;
	string pass;
	int group;
public:
	User();
	~User();
	void Setlogin(string login_);
	void Setpass(string pass_);	
	void Setgroup(int group_);
	void Setlogin();
	void Setpass();
	void Setgroup();
	string Getlogin();
	string Getpass();
	int Getgroup();
};

