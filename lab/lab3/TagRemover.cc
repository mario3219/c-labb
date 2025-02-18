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

TagRemover::TagRemover(std::istream& input) : text(""), result("") {
    string str;
    while (getline(input, str)) {
        text += str;
    }
};

string TagRemover::getText() {
    return text;
}

string TagRemover::getResult() {
    return result;
}

string TagRemover::removeTags() {
    bool tag = false;
    for (char c : text) {
        if (c == '<') {
            tag = true;
        } else if (c == '>') {
            tag = false;
        } else if (!tag) {
            result += c;
        }
    }
    return result;
}