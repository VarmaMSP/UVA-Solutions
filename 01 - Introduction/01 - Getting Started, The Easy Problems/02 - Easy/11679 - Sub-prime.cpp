#include <bits/stdc++.h>

int main() {
    int b, n, bank[21], d, c, v;
    while (scanf("%d %d", &b, &n) && b && n) {
        for (int i = 1; i <= b; ++i) {
            scanf("%d", bank + i);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d %d %d", &d, &c, &v);
            bank[d] -= v;
            bank[c] += v;
        }
        bool bailout = false;
        for (int i = 1; i <= b; ++i) {
            if (bank[i] < 0) {
                bailout = true;
                break;
            }
        }
        puts(bailout ? "N" : "S");
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 28-Jun-2018
*/
