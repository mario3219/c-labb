# include "dictionary.h"
# include <iostream>
# include "word.h"
# include "trigrams.h"

int main() {
	Dictionary dict;
	std::string str = "dwadawd";
	std::cout << dict.contains(str) << "\n";
	std::vector<std::string> candidates = dict.add_trigram_suggestions("aachen");
	for (std::string str : candidates) {
		std::cout << str << "\n";
	}
	dict.trim_suggestions("aachen",candidates);
	return 0;
}
