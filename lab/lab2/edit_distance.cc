#include <iostream>
#include "edit_distance.h"
#include <algorithm>

using namespace std;

int edit_distance(const string& x, const string& y) {
    int const m = x.size();
    int const n = y.size();
    int d[m+1][n+1];

    for (size_t i = 0; i <= x.size(); ++i) {d[i][0] = i;}
    for (size_t j = 0; j <= y.size(); ++j) {d[0][j] = j;}

    for (size_t i = 1; i <= x.size(); ++i) {
        for (size_t j = 1; j <= y.size(); ++j) {
            if (x[i-1] == y[j-1]) {
                d[i][j] = d[i-1][j-1];
            } else {
                int a = d[i-1][j-1]+1;
                int b = d[i-1][j]+1;
                int c = d[i][j-1]+1;
                d[i][j] = min({a,b,c});
            }
        }
    }
    return d[x.size()][y.size()];
}