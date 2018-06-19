# Company

#pragma once
#include<iostream>

class Company
{
public:
	Company(const char* name = "NO NAME", int tP = 0, int sP = 0);
	Company(const Company& c) { CopyFrom(c); }
	Company& operator=(const Company&);
	virtual ~Company() { delete[] name; }

	void setName(const char* name);
	void setTakenProjects(int tP) { takenProjects = tP; }
	void setSuccessfulProjects(int sP) { successfulProjects = sP; }
	void TakeOnANewProject() { takenProjects += 1; }
	void enterAsSuccess() { successfulProjects += 1; }

	int getTakenProjects() const { return takenProjects; }
	char* getName() const { return name; }
	int getSuccessfulProjects() const { return successfulProjects; }
	
	virtual bool perform(const char* task) = 0;
	virtual double reliabilityRate() const = 0;
	virtual void print() const = 0;
private:
	void CopyFrom(const Company& c);

	char* name;
	int takenProjects;
	int successfulProjects;
};
