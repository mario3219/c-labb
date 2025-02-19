#include <iostream>
#include <sstream>
#include "TagRemover.h"

using namespace std;

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
    cout << "result: " << result << "\n";
    if (result != test) {
        cout << "Failure at: This is a line without a tag" << "\n";
        return false;
    }

    test = "This is <tag tag> a line with one tag";
    istringstream testStream2(test);
    TagRemover tr2(testStream2);
    goal = "This is  a line with one tag";
    result = tr2.removeTags();
    cout << "result2: " << result << "\n";
    if (result != goal) {
        cout << "Failure at: This is <tag tag> a line with one tag" << "\n";
        return false;
    }
    
    cout << "Pass" << "\n";

    return true;
}

// string test_specCharRemover(string str) {
//     // TagRemover tr(str);
//     // tr.removeSpecChars();
//     // return tr.print();
// }#include <iostream>
#include <sstream>
#include "TagRemover.h"

using namespace std;

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
    cout << "result: " << result << "\n";
    if (result != test) {
        cout << "Failure at: This is a line without a tag" << "\n";
        return false;
    }

    test = "This is <tag tag> a line with one tag";
    istringstream testStream2(test);
    TagRemover tr2(testStream2);
    goal = "This is  a line with one tag";
    result = tr2.removeTags();
    cout << "result2: " << result << "\n";
    if (result != goal) {
        cout << "Failure at: This is <tag tag> a line with one tag" << "\n";
        return false;
    }
    
    cout << "Pass" << "\n";

    return true;
}

// string test_specCharRemover(string str) {
//     // TagRemover tr(str);
//     // tr.removeSpecChars();
//     // return tr.print();
// }

int main() {
    test_tagRemover();
    return 0;
}
    

