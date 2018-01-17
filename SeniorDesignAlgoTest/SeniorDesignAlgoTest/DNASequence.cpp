#include "DNASequence.h"
using namespace std;

namespace SeniorDesign 
{

	DNASequence::DNASequence() : sequence(0), count(0) {}
	DNASequence::DNASequence(size_t count) : sequence(count), count(count)
	{
	}

	DNASequence::DNASequence(vector<BasePair> sequence) : sequence( sequence ) 
	{
		count = sequence.size();
	}


	DNASequence::~DNASequence()
	{
	}

	BasePair DNASequence::operator[](const size_t pos) 
	{
		return sequence[pos];
	}

	BasePair DNASequence::operator[](const size_t pos) const 
	{
		return sequence[pos];
	}

	size_t DNASequence::GetCount() const
	{
		return count;
	}

	DNASequence& DNASequence::operator=(const DNASequence& rhs)
	{
		sequence = vector<BasePair>(rhs.sequence);
		return *this;
	}

	void DNASequence::AddBasePair(const BasePair& bp) 
	{
		sequence.insert(sequence.end(), bp);
		count++;
	}

	ostream& operator << (ostream& os, const DNASequence& dna) 
	{
		for (int i = 0; i < dna.count; i++)
		{
			os << BasePairLibrary::TranslateBinary(dna[i]);
		}
		return os;
	}

	DNASequence& operator << (DNASequence& dna, char bp) 
	{
		dna.AddBasePair(BasePairLibrary::TranslateBasePair(bp));
		return dna;
	}

	DNASequence& operator << (DNASequence& lhs, const BasePair& rhs) 
	{
		lhs.AddBasePair(rhs);
		return lhs;
	}

	DNASequence& operator << (DNASequence& lhs, const DNASequence& rhs) 
	{
		for each (BasePair bp in rhs.sequence) 
		{
			lhs.AddBasePair(bp);
		}
		return lhs;
	}
	
	BasePair DNALibrary::PAMArray[3]{ BasePair(0xf), BasePair(0x4), BasePair(0x4) };

	const DNASequence DNALibrary::PAMsequence( vector<BasePair>(PAMArray, PAMArray + sizeof(PAMArray) / sizeof(BasePair)) );

	DNASequence& DNALibrary::ParseSequence(const string& sequence)
	{
		DNASequence result(sequence.size());
		for each (char bp in sequence)
		{
			result << bp;
		}
		return result;
	}

	DNASequence& DNALibrary::AddPAM(DNASequence& sequence) 
	{
		sequence << PAMsequence;
		return sequence;
	}
}