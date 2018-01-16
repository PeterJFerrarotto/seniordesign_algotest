#include "BasePairLibrary.h"
using namespace std;


const bitset<4> BasePairLibrary::Uracil{ std::string("0000") };
const bitset<4> BasePairLibrary::Adenine{ std::string("0001") };
const bitset<4> BasePairLibrary::Cytosine{ std::string("0010") };
const bitset<4> BasePairLibrary::Guanine{ std::string("0100") };
const bitset<4> BasePairLibrary::Thymine{ std::string("1000") };

const map<char, bitset<4>> BasePairLibrary::BasePairMap{ {'U', Uracil}, {'A', Adenine}, {'C', Cytosine}, {'G', Guanine}, {'T', Thymine} };