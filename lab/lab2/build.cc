# include <iostream>
# include <algorithm>
# include <vector>
# include "trigrams.h"

using namespace std;

int main() {
    string s;
    while (cin >> s) {
        transform(s.begin(), s.end(), s.begin(),[](unsigned char c) { return std::tolower(c); });
        vector<string> trigrams = find_trigrams(s);
        cout << s << " " << trigrams.size() << " ";
        for (string tri : trigrams) {
            cout << tri << " ";
        }
        cout << "\n";
    }
    return 0;
}
