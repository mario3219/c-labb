#include <iostream>
#include "TagRemover.h"

using namespace std;

string test_tagRemover(string str) {
    TagRemover tr();
    string result;
    string test;

    test = "This is a line without a tag";
    tr.setString("This is a line without a tag");
    result = tr.removeTags();
    if (tr)
    
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