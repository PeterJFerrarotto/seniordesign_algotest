#include <iostream>
#include <string>
#include "BasePairLibrary.h"
#include "DNASequence.h"
using namespace std;
using namespace SeniorDesign;

int main()
{
	try {
		BasePair test{ 0x1 };
		cout << test << endl;
		cout << BasePairLibrary::TranslateBinary(test) << endl;
		cout << BasePairLibrary::GetCompliment(test) << endl;
		BasePair test2;
		test2 = BasePairLibrary::GetRNACompliment(test);
		cout << test2 << endl;
		cout << DNALibrary::PAMsequence << endl;
		char basePair;
		cin >> basePair;
		while (!BasePairLibrary::ValidBasePair(basePair))
		{
			cin >> basePair;
		}
		cout << endl;
		cout << BasePairLibrary::TranslateBasePair(basePair) << endl;
		string sequence;
		DNASequence guideSequence;
		for (int i = 0; i < 20; i++) 
		{
			cin >> basePair;
			while (!BasePairLibrary::ValidBasePair(basePair)) 
			{
				cout << "Invalid base pair: " << basePair << endl;
				cin >> basePair;
			}
			guideSequence << basePair;
		}
		guideSequence = DNALibrary::AddPAM(guideSequence);
		cout << guideSequence;
	}
	catch (exception ex)
	{
		cout << ex.what();
	}
	string junk;
	cin >> junk;
	return 0;
}
