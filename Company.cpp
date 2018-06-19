# Company

#include "Company.h"


Company::Company(const char* name, int tP, int sP) : takenProjects(tP), successfulProjects(sP)
{
	setName(name);
}

Company& Company::operator=(const Company&c)
{
	if (this != &c)
	{
		delete[] name;
		CopyFrom(c);
	}
	return *this;
}

void Company::CopyFrom(const Company& c)
{
	takenProjects = c.takenProjects;
	successfulProjects = c.successfulProjects;
	setName(c.name);
}

void Company::setName(const char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}
