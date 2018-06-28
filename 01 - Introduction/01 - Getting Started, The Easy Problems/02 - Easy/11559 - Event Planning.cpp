#include <bits/stdc++.h>

int main() {
    int n, b, h, w, p, available;
    while (scanf("%d %d %d %d", &n, &b, &h, &w) != EOF) {
        int cost = INT_MAX;
        while (h--) {
            scanf("%d", &p);
            for (int i = 0; i < w; ++i) {
                scanf("%d", &available);
                if (n <= available && n * p < cost) {
                    cost = n * p;
                }
            }
        }
        if (cost < b) {
            printf("%d\n", cost);
        } else {
            puts("stay home");
        }
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 28-Jun-2018
*/
