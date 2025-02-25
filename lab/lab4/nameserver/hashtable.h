#ifndef HASHTABLE_H
#define HASHTABLE_H

using namespace std;

class HashTable {
    public:
        // constructors
        HashTable()=default;
        HashTable()

    private:
        // private member variables
        vector<pair<Key, Value>> table;
        
        //  private functions

        // generates hash code
        size_t hash(const Key& key) const {
            return 0;
        }

        // resizes the vector table
        void resize() {};

}

#endif