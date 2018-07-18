#include <bits/stdc++.h>

int m, n, g[11][11], s[10];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool visit[11][11];

int floodfill(int x, int y) {
    if (x < m || x >= n || y < m || y >= n || visit[x][y]) return 0;
    visit[x][y] = true;
    int c = g[x][y];
    for (int i = 0; i < 4; ++i) {
        int X = dx[i] + x;
        int Y = dy[i] + y;
        c += floodfill(X, Y);
    }
    return c;
}

int main() {
    int l, c = 1;
    while (scanf("%d", &n) && n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", g[i] + j);
            }
        }
        l = 0, m = 0;
        while (m < n) {
            s[l] = floodfill(m, m);
            memset(visit, false, sizeof(visit));
            l += 1, m += 1, n -= 1;
        }
        for (int i = 0; i < l - 1; ++i) {
            s[i] -= s[i + 1];
        }
        printf("Case %d:", c++);
        for (int i = 0; i < l; ++i) {
            printf(" %d", s[i]);
        }
        printf("\n");
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 18-Jul-2018
*/
