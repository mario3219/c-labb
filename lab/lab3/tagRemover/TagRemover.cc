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
    cout << "constructor: " << text << "\n";
}

string TagRemover::specCharRemover() {
    string temp;
    map<string,string> mp;
    size_t pos;
    mp["&lt"] = "<";
    mp["&gt"] = ">";
    mp["&nbsp"] = " ";
    mp["&amp"] = "&";

    for (auto x = mp.begin(); x != mp.end(); ++x) {
        pos = text.find(x->first);
        while (pos != string::npos) {
            text.replace(pos, x->first.length(), x->second);
            pos = text.find(x->first);
        }
    }
    return text;
};

string TagRemover::removeTags() {

    size_t pos1 = text.find("<");
    size_t pos2 = text.find(">");
    while (pos1 != string::npos && pos2 != string::npos) {
        text.erase(pos1, pos2-pos1+1);
        pos1 = text.find("<");
        pos2 = text.find(">");
    } return text;

    /* bool tag = false;
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
    return text; */
}

void TagRemover::print(std::istream& output) {
    cout << text << "\n";
}

string TagRemover::getText() {
    return text;
}