#include <iostream>
#include "umns.h"
#include <vector>

using namespace std;

void test_Constructor() {
    // testing default constructor
    UMNS test;

    // testing input pair
    std::pair<HostName, IPAddress> pair("test",123);
    UMNS vns(pair);

    // testing input HostName, IPAdress
    UMNS("test",123);

    cout << "Constructor: Success" << "\n";
}

void test_lookup() {
    UMNS test("test",123);
    IPAddress address = test.lookup("test");
    if (address == 123) {
        cout << "Lookup: Success" << "\n";
    } else {
        cout << "Lookup: Failure" << "\n";
    }
}

void test_insert() {
    UMNS test;
    test.insert("test",123);

    cout << "Insert: Success" << "\n";
}

void test_remove() {
    UMNS test;
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