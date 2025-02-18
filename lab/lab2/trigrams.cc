# include <iostream>
# include <algorithm>
# include <vector>
# include "trigrams.h"

using namespace std;

vector<string> find_trigrams(const string &s) {
    vector<string> trigrams;
    int sz = s.size();
    for (int idx = 0; idx+3 <= sz; ++idx) {
        trigrams.push_back(
            string(s.begin()+idx, s.begin()+idx+3)
        );
    }
    sort(trigrams.begin(), trigrams.end());
    return trigrams;
}