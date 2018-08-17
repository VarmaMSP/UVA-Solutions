#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n, c, d, x = 1;
    int p[22], on[22];
    while (scanf("%d %d %d", &n, &m, &c) && (n|m|c)) {
        memset(on, 0, sizeof(on));
        for (int i = 0; i < n; ++i) {
            scanf("%d", p + i);
        }
        int maxPow = INT_MIN;
        while (m--) {
            scanf("%d", &d);
            on[d - 1] ^= 1;
            int s = 0;
            for (int i = 0; i < n; ++i) {
                s += on[i] * p[i];
            }
            maxPow = max(s, maxPow);
        }
        printf("Sequence %d\n", x++);
        if (maxPow > c) {
            printf("Fuse was blown.\n");
        } else {
            printf("Fuse was not blown.\n");
            printf("Maximal power consumption was %d amperes.\n", maxPow);
        }
        printf("\n");
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 17-Aug-2018
*/
