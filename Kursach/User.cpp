#include "User.h"

User::User()
{
	login = "";
	pass = "";
	group = NULL;
}

User::~User()
{
}

void User::Setlogin()
{
	login = "";
}

void User::Setlogin(string login_)
{
	login = login_;
}

void User::Setpass(string pass_)
{
	pass = pass_;
}

void User::Setpass()
{
	pass = "";
}

void User::Setgroup(int group_)
{
	group = group_;
}

void User::Setgroup()
{
	group = NULL;
}

string User::Getlogin()
{
	return login;
}

string User::Getpass()
{
	return pass;
}

int User::Getgroup()
{
	return group;
}