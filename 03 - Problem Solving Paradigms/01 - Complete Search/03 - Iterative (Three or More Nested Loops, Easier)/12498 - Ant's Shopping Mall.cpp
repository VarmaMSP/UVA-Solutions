#include <bits/stdc++.h>

int main() {
    int tt, R, C, g[55][55], x = 1;
    char str[55];
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d %d", &R, &C);
        for (int i = 0; i < R; ++i) {
            scanf("%s", str);
            for (int j = 0; j < C; ++j) {
                g[i][j] = str[j] - '0';
            }
        }
        int min = INT_MAX;
        for (int c = 0; c < C; ++c) {
            int moves = 0;
            bool isPoss = true;
            for (int r = 0; r < R && isPoss; ++r) if (g[r][c]) {
                int left = 0, right = 0;
                bool lf = false, rf = false;
                for (int i = c - 1; i >= 0; --i) {
                    if (!g[r][i]) { lf = true; break; }
                    left += 1;
                }
                for (int i = c + 1; i < C; ++i) {
                    if (!g[r][i]) { rf = true; break; }
                    right += 1;
                }
                if (!rf && !lf) isPoss = false;
                if (!rf && lf) moves += left + 1;
                if (rf && !lf) moves += right + 1;
                if (rf && lf) moves += left > right ? right + 1 : left + 1;
            }
            if (isPoss && moves < min) min = moves;
        }
        printf("Case %d: %d\n", x++, min == INT_MAX ? -1 : min);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 5-July-2018
*/
