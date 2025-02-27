#include "bitreference.h"
#include "bitset.h"

BitReference& BitReference::operator=(bool b) {
	//
	// *** IMPLEMENT ***
	// This corresponds to the set() function in SimpleBitset.
	//
	 // for bs[i] = b
	if (b) {
		*p_bits |= 1L << pos;
	} else {
		*p_bits &= ~ (1L << pos);
	}
	return *this;
}

BitReference& BitReference::operator=(const BitReference& rhs) {
	//
	// *** IMPLEMENT ***
	// Same as operator=(bool), but the bit is picked from rhs
	//
	// for bs[i] = bs[j]
	bool b = (*p_bits & (1L << pos)) != 0;

	auto bit_1 = *p_bits << pos;
	auto bit_2 = *rhs.p_bits << rhs.pos;

	if (b) {
		bit_1 |= bit_2;
	} else {
		bit_2 &= ~ bit_2;
	}
	
	return *this;
}

BitReference::operator bool() const {
	//
	// *** IMPLEMENT ***
	// This corresponds to the get() function in SimpleBitset.
	//
	 // for b = bs[i]
	return (*p_bits & (1L << pos)) != 0;
}
