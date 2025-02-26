#include <iostream>
#include "hns.h"
#include <vector>

using namespace std;

void test_Constructor() {
    HNS test(100);

    cout << "Constructor: Success" << "\n";
}

void test_lookup() {
    HNS test(100);
    test.insert("test",123);
    IPAddress address = test.lookup("test");
    if (address == 123) {
        cout << "Lookup: Success" << "\n";
    } else {
        cout << "Lookup: Failure" << "\n";
    }
}

void test_insert() {
    HNS test(100);
    test.insert("test",123);

    cout << "Insert: Success" << "\n";
}

void test_remove() {
    HNS test(100);
    test.insert("test",123);
    test.remove("test");
    IPAddress address = test.lookup("test");
    if (address == NON_EXISTING_ADDRESS) {
        cout << "Remove: Success" << "\n";
    } else {
        cout << "Remove: Failure" << "\n";
    }
}

int main() {
    test_Constructor();
    test_insert();
    test_lookup();
    test_remove();
    return 0;
}