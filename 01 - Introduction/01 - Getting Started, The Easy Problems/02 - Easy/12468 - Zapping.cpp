#include <bits/stdc++.h>

using namespace std;

inline int mod(int a) {
    return a > 0 ? a : -a;
}

int main() {
    int a, b;
    while (scanf("%d %d", &a, &b) && a != -1 && b != -1) {
        int d1 = mod(b - a);
        int d2 = 100 - d1;
        printf("%d\n", min(d1, d2));
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 30-Jun-2018
*/
