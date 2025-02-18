#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <sstream>
#include <map>
#include "TagRemover.h"

using namespace std;

TagRemover::TagRemover(std::istream& input) {
    string text;
    while (getline(input, str)) {
        text.push_back(str);
    }
}

string TagRemover::specCharRemover(string& str) {
    
}