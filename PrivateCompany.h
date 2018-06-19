# Company

#pragma once
#include "Company.h"
class PrivateCompany :
	public Company
{
public:
	PrivateCompany(const char* name = "NO NAME", int tP = 0, int sP = 0, int sR = 0);

	bool perform(const char* task);
	double reliabilityRate() const;
	void print() const { std::cout << "Private company : " << successRate << " " << getName(); }
private:
	int successRate;
};

