#include <iostream>
#include "TagRemover.h"

using namespace std;

bool test_tagRemover(string str) {
    TagRemover tr();
    string test;
    string goal;
    string result;

    test = "This is a line without a tag";
    tr.setString(test);
    result = tr.removeTags();
    if (result != test) {return false;}

    test = "This is <tag tag> a line with one tag";
    goal = "This is a line with one tag";
    tr.setString(test);
    result = tr.removeTags();
    if (result != goal) {return false;}
    
    return true;
}

int main() {
    string str = "test";
    string result = test_TagRemover(str);
    if (result == str) {
        cout << "Success" << "\n";
    } else {
        cout << "Failure" << "\n";
    }
}

string test_specCharRemover(string str) {
    TagRemover tr(str);
    tr.removeSpecChars();
    return tr.print();
}
    

