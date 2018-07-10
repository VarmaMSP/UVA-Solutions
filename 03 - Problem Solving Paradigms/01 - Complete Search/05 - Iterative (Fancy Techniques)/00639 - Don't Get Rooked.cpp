#include <bits/stdc++.h>

int main() {
    int n;
    char g[5][5];
    while (scanf("%d", &n) && n) {
        for (int i = 0; i < n; ++i) {
            scanf("%s", g[i]);
        }
        int max = INT_MIN;
        for (int s = 0; s < (1 << (n*n)); ++s) {
            int count = 0;
            bool isValid = true;
            for (int p = 0; p < n * n; ++p) if (s & (1 << p)) {
                int x = p / n;
                int y = p % n;
                if (g[x][y] == 'X') {
                    isValid = false;
                    break;
                }
                for (int i = x - 1; i >= 0 && isValid; --i) {
                    if (g[i][y] == 'r') isValid = false;
                    if (g[i][y] == 'X') break;
                }
                for (int i = y - 1; i >= 0 && isValid; --i) {
                    if (g[x][i] == 'r') isValid = false;
                    if (g[x][i] == 'X') break;
                }
                if (isValid) {
                    g[x][y] = 'r';
                    count += 1;
                }
            }
            if (isValid && count > max) max = count;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (g[i][j] == 'r') g[i][j] = '.';
                }
            }
        }
        printf("%d\n", max);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 10-July-2018
*/
