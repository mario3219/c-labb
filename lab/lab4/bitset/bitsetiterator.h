/*
 * A BitsetIterator is an iterator for Bitsets.
 * Postfix ++, ==, and -> are not implemented.
 */

#ifndef BITSET_ITERATOR_H
#define BITSET_ITERATOR_H

#include "bitreference.h"
#include <iterator>

class BitsetIterator : public std::iterator<std::forward_iterator_tag, bool> {
public:
	BitsetIterator(Bitset::BitStorage* pb, std::size_t p) : ref(pb, p) {}

    BitsetIterator(const BitsetIterator&) =default;

	bool operator!=(const BitsetIterator& bsi) const {
		if (ref.pos != bsi.ref.pos) {
			return true;
		} return false;
	}

	BitsetIterator& operator++() {
		++ref.pos;
		return *this;
	}

	BitReference operator*() {
		return BitReference(ref.p_bits,ref.pos);
	}

	BitsetIterator& operator=(const BitsetIterator& rhs) {
		ref.p_bits = rhs.ref.p_bits;
		ref.pos = rhs.ref.pos;
		return *this;
	}
private:
	BitReference ref;
};

#endif

