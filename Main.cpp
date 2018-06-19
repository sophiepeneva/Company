# Company

#include "Consortium.h"
#include<iostream>

using namespace std;

int main()
{
	StateOwnedCompany soc1("soc1",0,0);
	PrivateCompany pc1("pc1", 0, 0, 2);
	Consortium cons1;
	Consortium cons2;

	cons1.AddSubcontractor(pc1);
	cons2.AddSubcontractor(soc1);
	cons1.AddSubcontractor(cons2);
	cons1.perform("build residential builging");
	cons1.perform("run educational programme");
	cons1.perform("translate document");
	cons1.printStatus();
	cout << cons1.reliabilityRate() << endl;

	system("pause");
}
