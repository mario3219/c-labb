#include <iostream>
#include <sstream>
#include "TagRemover.h"

using namespace std;

bool test_tagRemover() {
    string test;
    string goal;
    string result;

    cout << "test_tagRemover - ";

    test = "This is a line without a tag";
    istringstream testStream1(test);
    TagRemover tr(testStream1);
    result = tr.removeTags();
    //cout << "result: " << result << "\n";
    if (result != test) {
        cout << "Failure at: This is a line without a tag" << "\n";
        cout << "Result: " << result << "\n";
        return false;
    }

    test = "This is <tag tag> a line with one tag";
    istringstream testStream2(test);
    TagRemover tr2(testStream2);
    goal = "This is  a line with one tag";
    result = tr2.removeTags();
    //cout << "result2: " << result << "\n";
    if (result != goal) {
        cout << "Failure at: This is <tag tag> a line with one tag" << "\n";
        cout << "Result: " << result << "\n";
        return false;
    }
    
    cout << "Pass" << "\n";

    return true;
}

void test_specCharRemover() {
    cout << "test_specCharRemover - ";
    
    string test = "&lt;&gt;&nbsp;&amp";
    istringstream testStream1(test);
    TagRemover tr(testStream1);
    string result = tr.specCharRemover();

    if (result == "<;>; ;&") {
        cout << "Pass" << "\n";
    } else {
        cout << "Failure, got: " << result << "\n";
    }

}

int main() {
    test_tagRemover();
    test_specCharRemover();

    TagRemover tr(std::cin);
    tr.removeTags();
    tr.specCharRemover();
    tr.print(std::cout);
    return 0;
}
    

