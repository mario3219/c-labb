#ifndef HNS_H
#define HNS_H

#include <iostream> //for debugging
#include "nameserverinterface.h"
#include <vector>
#include <algorithm>

using namespace std;

class HNS : public NameServerInterface {
    public:
        // constructors
        HNS(int size) {
            /* ändrade från reserve till resize
            hashtable.reserve(size);

            Reserve allokerar minne till vektorn, men ändrar inte
            på dess storlek. När hashtable.size() kallades i insert()
            så ledde det till en division med noll
            */
            hashtable.resize(size);
        }

        // default destructor
        ~ HNS()=default;

        // functions
        void insert(const HostName& name, const IPAddress& address) {
            size_t index = std::hash<HostName>()(name) % hashtable.size();
            hashtable[index].emplace_back(name, address);
        };

        bool remove(const HostName& name) {
            size_t index = std::hash<HostName>()(name) % hashtable.size();
            auto& bucket = hashtable[index];
            auto it = std::find_if(bucket.begin(), bucket.end(),
            [name](const std::pair<HostName, IPAddress>& pair) {return pair.first == name;}
            );            
            if (it != bucket.end()){
                bucket.erase(it);
                return true;
            }
            return false;
        };

        IPAddress lookup(const HostName& name) const {
            size_t index = std::hash<HostName>()(name) % hashtable.size();
            auto& bucket = hashtable[index];
            auto it = std::find_if(bucket.begin(), bucket.end(),
            [name](const std::pair<HostName, IPAddress>& pair) {return pair.first == name;}
            );
            /*Bytte plats på returnen, var return
            NON_EXISTING_ADDRESS när it != bucket.end innan*/
            if (it != bucket.end()){
                return it->second;
            } return NON_EXISTING_ADDRESS;
        };

    private:
        vector<vector<std::pair<HostName, IPAddress>>> hashtable;
};

#endif