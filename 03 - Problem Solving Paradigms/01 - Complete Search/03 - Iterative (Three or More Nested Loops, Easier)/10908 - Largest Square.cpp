#include <bits/stdc++.h>

int main() {
    int tt, m, n, q, r, c;
    char g[110][110];
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d %d %d", &m, &n, &q);
        printf("%d %d %d\n", m, n, q);
        for (int i = 0; i < m; ++i) {
            scanf("%s", g[i]);
        }
        int L = m < n ? m : n;
        while (q--) {
            scanf ("%d %d", &r, &c);
            int res;
            char x = g[r][c];
            for (int l = 1; l <= L; l += 2) {
                bool isSq = true;
                for (int i = r - (l / 2); i <= r + (l / 2) && isSq; ++i) {
                    if (i < 0 || i >= m) isSq = false;
                    for (int j = c - (l / 2); j <= c + (l / 2) && isSq; ++j) {
                        if (j < 0 || j >= n || g[i][j] != x) isSq = false;
                    }
                }
                if (isSq) res = l;
            }
            printf("%d\n", res);
        }
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 9-July-2018
*/
