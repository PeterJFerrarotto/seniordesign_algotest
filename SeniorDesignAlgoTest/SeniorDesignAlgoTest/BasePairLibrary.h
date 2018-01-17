#include <bitset>
#include <map>
#include <vector>
#ifndef _BASEPAIRLIBRARY_H
#define _BASEPAIRLIBRARY_H

namespace SeniorDesign 
{	
	class BasePair 
	{
	private:
		std::bitset<4> bRep;
	public:

		bool test(size_t pos) const;

		std::bitset<4> getBitRep() const;

		void setBitPos(size_t pos, bool val);

		bool operator== (const BasePair& rhs) const;
		bool operator!= (const BasePair& rhs) const;

		bool operator< (const BasePair& rhs) const;
		bool operator> (const BasePair& rhs) const;
		bool operator>= (const BasePair& rhs) const;
		bool operator<= (const BasePair& rhs) const;

		bool operator== (const std::bitset<4>& rhs) const;
		bool operator!= (const std::bitset<4>& rhs) const;

		BasePair& operator = (const BasePair& rhs);
		BasePair& operator = (const std::bitset<4>& rhs);
		friend std::ostream& operator<< (std::ostream& os, const BasePair& BP);
		BasePair();
		BasePair(std::bitset<4>);
		BasePair(const BasePair& copy);
	};

	static class BasePairLibrary
	{
	private:
		static BasePair U;
		static BasePair A;
		static BasePair C;
		static BasePair G;
		static BasePair T;
		static BasePair M;
		static BasePair R;
		static BasePair W;
		static BasePair S;
		static BasePair Y;
		static BasePair K;
		static BasePair V;
		static BasePair H;
		static BasePair D;
		static BasePair B;
		static BasePair N;

		static const std::map<char, BasePair> BasePairMap;
		static const std::map<BasePair, char> BinaryMap;

		static const std::map<BasePair, BasePair> Compliments;

		static std::bitset<4>& reverseOrder(const std::bitset<4>& bits);
		
	public:
		static std::vector<char> validBPChars;
		static char TranslateBinary(const BasePair& BasePair);

		static BasePair TranslateBasePair(const char BasePair);

		static BasePair& GetCompliment(const BasePair& BasePair);

		static BasePair& GetRNACompliment(const BasePair& BasePair);

		static bool MatchBasePair(const BasePair& bp1, const BasePair& bp2);

		static bool ValidBasePair(char bp);
	};
}
#endif