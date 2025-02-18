#include <string>
#include <vector>
#include "word.h"
#include <algorithm>

using namespace std;

Word::Word(const string& w, const vector<string>& t) : word(w), trigrams(t) {}

string Word::get_word() const {
	return word;
}

unsigned int Word::get_matches(const vector<string>& t) const {
	int sum = 0;
	int count = 0;
	int incr = 0;
	for (string str : t) {
		if (trigrams.begin()+incr == trigrams.end()) {break;}
		count = std::count(trigrams.begin()+incr, trigrams.end(), str);
		if (count !=0) {++incr;}
		sum = sum + count;
		count = 0;
	} return sum;
}
