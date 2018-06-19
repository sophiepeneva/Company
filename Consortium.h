# Company

#pragma once
#include "Company.h"
#include "PrivateCompany.h"
#include "StateOwnedCompany.h"

class Consortium :
	public Company
{
public:
	Consortium(const char* name = "NO NAME", int tP = 0, int sP = 0, int nOS = 0);
	~Consortium() { Destroy(); }
	Consortium(const Consortium& c) { CopyFrom(c); }
	Consortium& operator=(const Consortium& c);
	void expand();
	bool perform(const char* task);
	double reliabilityRate() const;

	void AddSubcontractor(const StateOwnedCompany& sOC);
	void AddSubcontractor(const PrivateCompany& pC);
	void AddSubcontractor(const Consortium& c);
	void deleteSubcontractor(const char* name);
	void printStatus() const;
	void print() const { std::cout << "Consortium : " << numOfSubcontractors << " " << getName(); }
private:
	void Destroy();
	void CopyFrom(const Consortium& c);
	Company ** subcontractors;
	int maxSubscontractors = 10;
	int numOfSubcontractors;
};

