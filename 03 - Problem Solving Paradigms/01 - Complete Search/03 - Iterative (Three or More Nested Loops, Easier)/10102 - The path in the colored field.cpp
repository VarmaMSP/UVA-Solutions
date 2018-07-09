#include <bits/stdc++.h>

inline int abs(int i) {
    return i > 0 ? i : -i;
}

int main() {
    int m;
    char g[1010][1010];
    while (scanf("%d", &m) != EOF) {
        for (int i = 0; i < m; ++i) {
            scanf("%s", g[i]);
        }
        int max = INT_MIN;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) if (g[i][j] == '1') {
                int nearest = INT_MAX;
                for (int k = 0; k < m; ++k) {
                    for (int l = 0; l < m; ++l) if (g[k][l] == '3') {
                        int d = abs(i - k) + abs(j - l);
                        if (d < nearest) nearest = d;
                    }
                }
                if (nearest > max) max = nearest;
            }
        }
        printf("%d\n", max);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 6-July-2018
*/
