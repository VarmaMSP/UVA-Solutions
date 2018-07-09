#include <bits/stdc++.h>

int main() {
    int m, n;
    char g[1010][1010];
    while (scanf("%d %d", &m, &n) && m) {
        for (int i = 0; i < m; ++i) {
            scanf("%s", g[i]);
        }
        int total = 0;
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
            if (g[i][j] != '1') continue;
            for (int a = 0; a < m - i; ++a) for (int b = 0; b < n - j; ++b) {
                bool isRec = true;
                for (int k = 0; k <= a && isRec; ++k) for (int l = 0; l <= b && isRec; ++l) {
                    if (g[i + k][j + l] == '0') {
                        isRec = false;
                        break;
                    }
                }
                total += (int)isRec;
            }
        }
        printf("%d\n", total);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 7-July-2018
*/
