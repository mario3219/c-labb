#ifndef HNS_H
#define HNS_H

#include "nameserverinterface.h"
#include <vector>
#include <algorithm>

using namespace std;

class HNS : public NameServerInterface {
    public:
        // constructors
        HNS(int size) {
            hashtable.reserve(size);
        }

        // default destructor
        ~ HNS()=default;

        // functions
        void insert(const HostName& name, const IPAddress& address) {
            size_t index = std::hash<HostName>()(name) % hashtable.size();
            hashtable[index].emplace_back(name, adress);
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
            if (it != bucket.end()){
                return NON_EXISTING_ADDRESS;
            }
            return it->second;
        };

    private:
        vector<vector<std::pair<HostName, IPAddress>>> hashtable;
};

#endif