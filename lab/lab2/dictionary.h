#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include <unordered_set>
#include "word.h"

using namespace std;

class Dictionary {
public:
	Dictionary();
	bool contains(const string& word) const;
	vector<string> get_suggestions(const string& word) const;
	vector<string> trim_suggestions(const string& word, const vector<string> candidates) const;
	vector<string> add_trigram_suggestions(const string& word) const;
private:
	//std::unordered_set<std::string> dict;	//decprecated since A4
	static constexpr int maxlen{25};	// creates constant maxlen = 25
	vector<Word> words[maxlen];	// creates an array of 25 vectors
	vector<string> split_lines(const string& str) const;
};

#endif
