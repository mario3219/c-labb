#include <iostream>
#include "TagRemover.h"

using namespace std;

string test_tagRemover(string str) {
    TagRemover tr(str);
    return tr.print();
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
    

