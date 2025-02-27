#include "bitreference.h"
#include "bitset.h"
#include <iostream> //for debugging

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

	bool a = (*p_bits & (1L << pos)) != 0;			//kollar om this är 1 eller 0 i pos
	bool b = (*rhs.p_bits & (1L << rhs.pos)) != 0;	//kollar om rhs är 1 eller 0 i pos
	
	if (!a && b) {
		// om this är 0 och rhs är 1, ansätter till 1 i this på pos
		*p_bits |= 1L << pos;
	} else if (a && !b) {
		// om this är 1 och rhs är 0, ansätter till 0 i this på pos
		*p_bits &= ~ (1L << pos);
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
