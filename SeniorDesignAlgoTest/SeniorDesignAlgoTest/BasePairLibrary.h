#include <bitset>
#include <map>
#ifndef _BASEPAIRLIBRARY_H
#define _BASEPAIRLIBRARY_H

static class BasePairLibrary
{
public:
	static const std::bitset<4> Uracil;
	static const std::bitset<4> Adenine;
	static const std::bitset<4> Cytosine;
	static const std::bitset<4> Guanine;
	static const std::bitset<4> Thymine;
	static const std::map<char, std::bitset<4>> BasePairMap;
	static const std::map<std::bitset<4>, char> BinaryMap;

	static const std::bitset<4> TranslateBasePair(char BasePair);

	static const char TranslateBinary(std::bitset<4> BasePair);
};

#endif