#include <iostream>
#include <string>
#include "BasePairLibrary.h"
using namespace std;
using namespace SeniorDesign;

int main()
{
	string junk;
	try {
		BasePair test{ 0x1 };
		cout << test << endl;
		cout << BasePairLibrary::TranslateBinary(test) << endl;
		cout << BasePairLibrary::GetCompliment(test) << endl;
		BasePair test2;
		test2 = BasePairLibrary::GetRNACompliment(test);
		cout << test2;
		cin >> junk;
	}
	catch (exception ex)
	{
		cout << ex.what();
		cin >> junk;
	}
	return 0;
}
