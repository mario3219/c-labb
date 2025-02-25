#include <iostream>
#include "mns.h"
#include <vector>

using namespace std;

void test_Constructor() {
    // testing default constructor
    MNS test;

    // testing input pair
    Pair pair("test",123);
    MNS vns(pair);

    // testing input HostName, IPAdress
    MNS("test",123);

    cout << "Constructor: Success" << "\n";
}

void test_lookup() {
    MNS test("test",123);
    IPAddress address = test.lookup("test");
    if (address == 123) {
        cout << "Lookup: Success" << "\n";
    } else {
        cout << "Lookup: Failure" << "\n";
    }
}

void test_insert() {
    MNS test;
    test.insert("test",123);

    cout << "Insert: Success" << "\n";
}

void test_remove() {
    MNS test;
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