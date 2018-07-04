#include <bits/stdc++.h>

inline int mod(int a) {
    return a > 0 ? a : -a;
}

int main() {
    int n, m, q, a[1010], c = 1;
    while (scanf("%d", &n) && n) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
        }
        scanf("%d", &m);
        printf("Case %d:\n", c++);
        while (m--) {
            scanf("%d\n", &q);
            int res, diff = INT_MAX;
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    if (mod(q - a[i] - a[j]) < diff) {
                        diff = mod(q - a[i] - a[j]);
                        res = a[i] + a[j];
                    }
                }
            }
            printf("Closest sum to %d is %d.\n", q, res);
        }
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 4-July-2018
*/
