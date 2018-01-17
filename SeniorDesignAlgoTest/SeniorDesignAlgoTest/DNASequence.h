#include "BasePairLibrary.h"
#include <vector>
#ifndef _DNASEQUENCE_H
#define _DNASQEUENCE_H

namespace SeniorDesign 
{
	class DNASequence
	{
	private:
		std::vector<BasePair> sequence;
		size_t count;
	public:
		DNASequence();
		DNASequence(size_t count);
		DNASequence(std::vector<BasePair> sequence);
		~DNASequence();

		void AddBasePair(const BasePair& bp);

		BasePair operator[](const size_t pos);

		BasePair operator[](const size_t pos) const;

		DNASequence& operator=(const DNASequence& rhs);

		size_t GetCount() const;

		friend std::ostream& operator << (std::ostream& os, const DNASequence& dna);

		friend DNASequence& operator << (DNASequence& lhs, const char rhs);

		friend DNASequence& operator << (DNASequence& lhs, const BasePair& rhs);

		friend DNASequence& operator << (DNASequence& lhs, const DNASequence& rhs);
	};

	static class DNALibrary 
	{
	private:
		static BasePair PAMArray[3];
	public:
		static const DNASequence PAMsequence;

		static DNASequence& ParseSequence(const std::string& sequence);
		
		static DNASequence& AddPAM(DNASequence& sequence);
	};
}
#endif