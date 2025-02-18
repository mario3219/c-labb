#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include "TagRemover.h"

using namespace std;

TagRemover::TagRemover(std::istream& input) : text(""), result("") {
    string str;
    while (getline(input, str)) {
        text += str;
    }
}

string TagRemover::specCharRemover(string& str) {
    bool done = false;
    string toReplace = "test";
    string replaceWith = "new";
    size_t pos;
    while (pos != string::npos) {
        pos = str.find(toReplace);
        str.replace(pos, toReplace.length(), replaceWith);
    }
    return str;
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