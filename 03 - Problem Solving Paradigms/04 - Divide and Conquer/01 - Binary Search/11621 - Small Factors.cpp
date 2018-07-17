#include <bits/stdc++.h>

using namespace std;

typedef long long int i64;

i64 pow(i64 x, i64 y) {
    i64 res = 1;
    while (y) {
        if (y & 1) res *= x;
        x = x * x;
        y = y >> 1;
    }
    return res;
}

int main() {
    vector< int > s;
    for (int i = 0; i < 32; ++i) {
        for (int j = 0; j < 20; ++j) {
            i64 p = pow(2, i) * pow(3, j);
            if (p < INT_MAX) s.push_back(p);
        }
    }
    sort(s.begin(), s.end());
    int n;
    while (scanf("%d", &n) && n) {
        auto x = lower_bound(s.begin(), s.end(), n);
        printf("%d\n", *x);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 17-July-2018
*/
