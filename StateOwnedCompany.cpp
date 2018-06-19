# Company

#include "StateOwnedCompany.h"



StateOwnedCompany::StateOwnedCompany(const char* name, int tP, int sP) : Company(name, tP, sP)
{}

bool StateOwnedCompany::perform(const char* task)
{
	TakeOnANewProject();
	if ((getTakenProjects()-1) % 20 != 0)
	{
		std::cout << "Operation " << task << " unsuccessful!" << std::endl;
		return false;
	}
	enterAsSuccess();
	std::cout << "Operation " << task << " successfully completed!" << std::endl;
	return true;
}
double StateOwnedCompany::reliabilityRate() const
{
	if (getTakenProjects() == 0)return 0;
	return getSuccessfulProjects() / (double)getTakenProjects();
}
