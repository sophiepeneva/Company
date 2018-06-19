# Company

#pragma once
#include "Company.h"
class StateOwnedCompany :
	public Company
{
public:
	StateOwnedCompany(const char* name = "NO NAME", int tP = 0, int sP = 0);
	bool perform(const char* task);
	double reliabilityRate() const;
	void print() const { std::cout << "State owned company : " << getName(); }
};
