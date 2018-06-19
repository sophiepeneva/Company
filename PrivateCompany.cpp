# Company

#include "PrivateCompany.h"



PrivateCompany::PrivateCompany(const char* name, int tP, int sP, int sR)
	: Company(name, tP, sP), successRate(sR)
{}

bool PrivateCompany::perform(const char* task)
{
	TakeOnANewProject();
	if (getTakenProjects() % successRate == 0) 
	{
		std::cout << "Operation " << task << " unsuccessful!" << std::endl;
		return false; 
	}
	std::cout << "Operation " << task << " successfully completed!" << std::endl;
	enterAsSuccess();
	return true;
}


double PrivateCompany::reliabilityRate() const 
{
	if (getTakenProjects() == 0)return 0;
	return getSuccessfulProjects() /(double) getTakenProjects();
}
