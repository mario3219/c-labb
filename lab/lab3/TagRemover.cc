#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>
#include "TagRemover.h"

using namespace std;

TagRemover::TagRemover(std::istream& input) : text("") {
    string str;
    while (getline(input, str)) {
        text += str;
    }
}

string TagRemover::specCharRemover() {
    string temp;
    map<string,string> mp;
    mp["&lt"] = 
    mp["&gt"] =
    mp["&nbsp"] =
    string toReplace = "test";
    string replaceWith = "new";
    size_t pos;
    while (pos != string::npos) {
        pos = text.find(toReplace);
        text.replace(pos, toReplace.length(), replaceWith);
    }
    return text;
};

string TagRemover::getText() {
    return text;
}

string TagRemover::removeTags() {
    bool tag = false;
    string temp;
    for (char c : text) {
        if (c == '<') {
            tag = true;
        } else if (c == '>') {
            tag = false;
        } else if (!tag) {
            temp += c;
        }
    }
    text = temp;
    return text;
}