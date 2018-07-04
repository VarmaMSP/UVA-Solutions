#include <bits/stdc++.h>

int main() {
    int tt, d, n, x, y, p, kills[1025][1025];
    scanf("%d", &tt);
    while (tt--) {
        memset(kills, 0, sizeof(kills));
        scanf("%d %d", &d, &n);
        while (n--) {
            scanf("%d %d %d", &x, &y, &p);
            for (int k = x - d > 0 ? x - d : 0; k < 1025 && k <= x + d; ++k) {
                for (int l = y - d > 0 ? y - d : 0; l < 1025 && l <= y +d; ++l) {
                    kills[k][l] += p;
                }
            }
        }
        int X, Y, max = INT_MIN;
        for (int i = 0; i < 1025; ++i) {
            for (int j = 0; j < 1025; ++j) {
                if (kills[i][j] > max) {
                    max = kills[i][j];
                    X = i, Y = j;
                }
            }
        }
        printf("%d %d %d\n", X, Y, max);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 4-July-2018
*/
