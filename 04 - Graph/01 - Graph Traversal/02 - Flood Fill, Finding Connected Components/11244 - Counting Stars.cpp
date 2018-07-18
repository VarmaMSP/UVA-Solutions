#include <bits/stdc++.h>

int m, n;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
char g[110][110];

int floodfill(int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n) return 0;
    if (g[x][y] != '*') return 0;
    g[x][y] = '.';
    int c = 1;
    for (int i = 0; i < 8; ++i) {
        int X = x + dx[i];
        int Y = y + dy[i];
        c += floodfill(X, Y);
    }
    return c;
}

int main() {
    while (scanf("%d %d", &m, &n) && (m|n)) {
        for (int i = 0; i < m; ++i) {
            scanf("%s", g[i]);
        }
        int stars = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (g[i][j] == '*') {
                    stars += floodfill(i, j) == 1 ? 1 : 0;
                }
            }
        }
        printf("%d\n", stars);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 18-Jul-2018
*/
