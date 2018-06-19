# Company

#include "Consortium.h"



Consortium::Consortium(const char* name, int tP, int sP, int nOS)
	: Company(name, tP, sP), numOfSubcontractors(nOS)
{
	subcontractors = new Company*[maxSubscontractors];
}

Consortium& Consortium::operator=(const Consortium& c)
{
	if (this != &c)
	{
		Destroy();
		CopyFrom(c);
	}
	return *this;
}

void Consortium::expand()
{
	Company ** temp = new Company*[numOfSubcontractors];
	for(int i=0;i<numOfSubcontractors;i++)
	{
		temp[i] = subcontractors[i];
	}
	maxSubscontractors += 10 ;
	subcontractors = new Company*[maxSubscontractors];
	for (int i = 0;i < numOfSubcontractors;i++)
	{
		subcontractors[i] = temp[i];
	}
	delete[] temp;
}

void Consortium::AddSubcontractor(const StateOwnedCompany& sOC)
{
	if (numOfSubcontractors + 1 == maxSubscontractors)expand();
	subcontractors[numOfSubcontractors++] = new StateOwnedCompany(sOC);
}

void Consortium::AddSubcontractor(const PrivateCompany& pC)
{
	if (numOfSubcontractors + 1 == maxSubscontractors)expand();
	subcontractors[numOfSubcontractors++] = new PrivateCompany(pC);
}

void Consortium::AddSubcontractor(const Consortium& c)
{
	if (numOfSubcontractors + 1 == maxSubscontractors)expand();
	subcontractors[numOfSubcontractors++] = new Consortium(c);
}

void Consortium::Destroy()
{
	for (int i = 0;i < numOfSubcontractors;i++)delete[] subcontractors[i];
	delete subcontractors;
}

bool Consortium::perform(const char* task)
{
	TakeOnANewProject();
	int min = 0;
	
	for (int i = 0;i < numOfSubcontractors;i++) 
	{
		if (subcontractors[i]->getTakenProjects() < subcontractors[min]->getTakenProjects())min = i;
	}
	bool wasASuccess = subcontractors[min]->perform(task);
	if (wasASuccess == true)enterAsSuccess();
	return wasASuccess;
}
double Consortium::reliabilityRate() const
{
	if (getTakenProjects() == 0)return 0;
	return getSuccessfulProjects() /(double) getTakenProjects();
}

void Consortium::deleteSubcontractor(const char* name)
{
	int index = -1;
	for (int i = 0;i < numOfSubcontractors;i++)
	{
		if(strcmp(subcontractors[i]->getName(),name)==0)
		{
			index = i;
		}
	}
	if (index != -1)
	{
		for (int i = index;i < numOfSubcontractors - 1;i++)
		{
			subcontractors[i] = subcontractors[i + 1];
		}
	}
}

void Consortium::printStatus() const
{
	for(int i=0;i<numOfSubcontractors;i++)
	{
		std::cout << subcontractors[i]->getName()
			<< " reliability : " << subcontractors[i]->reliabilityRate() << std::endl;
	}
}

void Consortium::CopyFrom(const Consortium& c)
{
	maxSubscontractors = c.maxSubscontractors;
	numOfSubcontractors = c.numOfSubcontractors;
	setName(c.getName());
	setTakenProjects(c.getTakenProjects());
	setSuccessfulProjects(c.getSuccessfulProjects());
	subcontractors = new Company*[maxSubscontractors];
	for (int i = 0;i < numOfSubcontractors;i++)
	{
		subcontractors[i] = c.subcontractors[i];
	}
}
