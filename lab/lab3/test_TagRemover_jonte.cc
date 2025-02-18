#include <iostream>
#include "TagRemover.h"

using namespace std;

bool test_tagRemover() {
    TagRemover tr();
    string test;
    string goal;
    string result;

    cout << "test_tagRemover - "

    test = "This is a line without a tag";
    tr.setString(test);
    result = tr.removeTags();
    if (result != test) {
        cout << "Failure at: This is a line without a tag" << "\n";
    return false;
    }

    test = "This is <tag tag> a line with one tag";
    goal = "This is a line with one tag";
    tr.setString(test);
    result = tr.removeTags();
    if (result != goal) {
        cout << "Failure at: This is <tag tag> a line with one tag" << "\n";
    return false;
    }
    
    cout << "Pass" << "\n";

    return true;
}

int main() {
    test_TagRemover(str);
    return 0;
}

string test_specCharRemover(string str) {
    TagRemover tr(str);
    tr.removeSpecChars();
    return tr.print();
}
    

