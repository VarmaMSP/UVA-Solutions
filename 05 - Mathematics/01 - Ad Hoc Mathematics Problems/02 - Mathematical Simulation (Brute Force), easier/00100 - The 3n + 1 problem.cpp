#include <bits/stdc++.h>
#define MAX 1000000

using namespace std;

typedef long long int i64;

int L[MAX + 10];

int cycle(i64 n) {
    int l = 0;
    while (n > 1) {
        l += 1;
        n = (n & 1) ? (3 * n + 1) : (n / 2);
        if (n <= MAX && L[n]) {
            return l + L[n];
        }
    }
    return l + 1;
}

int main() {
    int tt, x, y, X, Y;
    while (scanf("%d %d", &x, &y) != EOF) {
        X = x;
        Y = y;
        if (x > y) {
            swap(x, y);
        }
        int res = INT_MIN;
        for (int i = x; i <= y; ++i) {
            if (L[i] == 0) L[i] = cycle(i);
            res = max(res, L[i]);
        }
        printf("%d %d %d\n", X, Y, res);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 9-Aug-2018
*/
