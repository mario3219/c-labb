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

    cout << text << "\n";

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

    /* size_t pos;
    while (pos != string::npos) {
        pos = text.find(toReplace);
        text.replace(pos, toReplace.length(), replaceWith);
    } */

    cout << text << "\n";

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