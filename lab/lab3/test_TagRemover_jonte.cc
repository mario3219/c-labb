#include <iostream>
#include "TagRemover.h"

using namespace std;

bool test_tagRemover() {
    string test;
    string goal;
    string result;

    cout << "test_tagRemover - ";

    test = "This is a line without a tag";
    TagRemover tr(test);
    result = tr.removeTags();
    if (result != test) {
        cout << "Failure at: This is a line without a tag" << "\n";
    return false;
    }

    test = "This is <tag tag> a line with one tag";
    TagRemover tr(test);
    goal = "This is a line with one tag";
    result = tr.removeTags();
    if (result != goal) {
        cout << "Failure at: This is <tag tag> a line with one tag" << "\n";
    return false;
    }
    
    cout << "Pass" << "\n";

    return true;
}

int main() {
    test_TagRemover();
    return 0;
}

string test_specCharRemover(string str) {
    TagRemover tr(str);
    tr.removeSpecChars();
    return tr.print();
}
    

