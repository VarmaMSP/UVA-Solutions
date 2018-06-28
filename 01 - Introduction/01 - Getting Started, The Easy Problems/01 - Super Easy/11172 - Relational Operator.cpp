#include <bits/stdc++.h>

int main() {
    int tt, m, n;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d %d", &m, &n);
        if (m < n) {
            puts("<");
        }
        if (m > n) {
            puts(">");
        }
        if (m == n) {
            puts("=");
        }
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 28-Jun-2018
*/
