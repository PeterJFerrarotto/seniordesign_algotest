#include "BasePairLibrary.h"
using namespace std;

namespace SeniorDesign 
{
	BasePair::BasePair(bitset<4> binary) : bRep(binary) {}

	BasePair::BasePair() : bRep{ 0x0 } {}

	bitset<4> BasePair::getBitRep() const { return bRep; }

	bool BasePair::operator==(const BasePair& rhs) const
	{
		return bRep == rhs.bRep;
	}

	bool BasePair::operator!=(const BasePair& rhs) const 
	{
		return !(*this == rhs);
	}

	bool BasePair::operator< (const BasePair& rhs) const 
	{
		return bRep.to_ulong() < rhs.bRep.to_ulong();
	}

	bool BasePair::operator> (const BasePair& rhs) const
	{
		return rhs < *this;
	}

	bool BasePair::operator<= (const BasePair& rhs) const
	{
		return !(*this > rhs);
	}

	bool BasePair::operator>= (const BasePair& rhs) const
	{
		return !(*this < rhs);
	}

	bool BasePair::operator ==(const bitset<4>& rhs) const 
	{
		return bRep == rhs;
	}

	bool BasePair::operator !=(const bitset<4>& rhs) const 
	{
		return !(bRep == rhs);
	}

	bool BasePair::test(size_t pos) const 
	{
		return bRep.test(pos);
	}

	void BasePair::setBitPos(size_t pos, bool val) 
	{
		bRep.set(pos, val);
	}

	BasePair::BasePair(const BasePair& copy) : bRep(copy.bRep) {}

	ostream& operator<< (ostream& os, const BasePair& BP)
	{
		os << BP.bRep;
		return os;
	}

	BasePair& BasePair::operator=(const BasePair& rhs) 
	{
		bRep = rhs.bRep;
		return *this;
	}

	BasePair& BasePair::operator=(const bitset<4>& rhs) 
	{
		bRep = rhs;
		return *this;
	}

	BasePair BasePairLibrary::U{ 0x0 }; //0000
	BasePair BasePairLibrary::A{ 0x1 }; //0001
	BasePair BasePairLibrary::C{ 0x2 }; //0010
	BasePair BasePairLibrary::G{ 0x4 }; //0100
	BasePair BasePairLibrary::T{ 0x8 }; //1000
	BasePair BasePairLibrary::M{ 0x3 }; //0011
	BasePair BasePairLibrary::R{ 0x5 }; //0101
	BasePair BasePairLibrary::W{ 0x9 }; //1001
	BasePair BasePairLibrary::S{ 0x6 }; //0110
	BasePair BasePairLibrary::Y{ 0xa }; //1010
	BasePair BasePairLibrary::K{ 0xc }; //1100
	BasePair BasePairLibrary::V{ 0x7 }; //0111
	BasePair BasePairLibrary::H{ 0xb }; //1011
	BasePair BasePairLibrary::D{ 0xd }; //1101
	BasePair BasePairLibrary::B{ 0xe }; //1110
	BasePair BasePairLibrary::N{ 0xf }; //1111

	const map<BasePair, char> BasePairLibrary::BinaryMap{ {U, 'U'}, {A, 'A'}, {C, 'C'}, {G, 'G'}, {T, 'T'}, {M, 'M'}, {R, 'R'}, {W, 'W'}, {S, 'S'}, { Y, 'Y' }, { K, 'K' }, { V, 'V' }, { H, 'H' }, { D, 'D' }, { B, 'B' }, { N, 'N' } };

	char BasePairLibrary::TranslateBinary(const BasePair& BasePair)
	{
		return BinaryMap.at(BasePair);
	}

	bitset<4>& BasePairLibrary::reverseOrder(const std::bitset<4>& bits)
	{
		bitset<4> result;
		result[0] = bits[3];
		result[1] = bits[2];
		result[2] = bits[1];
		result[3] = bits[0];
		return result;
	}

	BasePair& BasePairLibrary::GetCompliment(const BasePair& basePair) 
	{
		BasePair compliment;
		bitset<4> binaryRep = basePair.getBitRep();
		if (binaryRep.to_ulong() == 0x0)
		{
			compliment = T;
		}
		else if (binaryRep.to_ulong() == 0x01 || binaryRep.to_ulong() == 0x02 || binaryRep.to_ulong() == 0x04 || binaryRep.to_ulong() == 0x08) 
		{
			compliment = reverseOrder(binaryRep);
		}
		else if (binaryRep.to_ulong() != 0xf) 
		{
			compliment = binaryRep.flip();
		}
		else 
		{
			compliment = N;
		}

		return compliment;
	}

	BasePair& BasePairLibrary::GetRNACompliment(const BasePair& basePair) 
	{
		BasePair compliment;
		bitset<4> binaryRep = basePair.getBitRep();
		if (binaryRep.to_ulong() == 0x8) 
		{
			compliment = U;
		}
		else if (binaryRep.to_ulong() == 0x1 || binaryRep.to_ulong() == 0x2 || binaryRep.to_ulong() == 0x4) 
		{
			compliment = reverseOrder(binaryRep);
		}
		else if (binaryRep.to_ulong() != 0xf)
		{
			compliment = binaryRep.flip();
		}
		else 
		{
			compliment = N;
		}

		return compliment;
	}

	bool BasePairLibrary::MatchBasePair(const BasePair& bp1, const BasePair& bp2) 
	{
		if (bp1.getBitRep() == 0x0) 
		{
			return bp1 == bp2 || (bp2.test(3) && (bp2.test(0) || bp2.test(1) || bp2.test(2)));
		}
		return ((bp1.test(0) && bp2.test(0)) || (bp1.test(1) && bp2.test(1)) || (bp1.test(2) && bp2.test(2)) || (bp1.test(3) && bp2.test(3)));
	}

}