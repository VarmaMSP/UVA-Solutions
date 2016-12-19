#include <bits/stdc++.h>

using namespace std;

int m, n, x, y;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char grid[25][25];

int floodfill(int r, int c, char c1, char c2) {
    if (r < 0 || c < 0 || r >= m || c >= n)
        return 0;
    if (grid[r][c] != c1)
        return 0;
    grid[r][c] = c2;
    int res = (r == x && c == y ? INT_MIN : 1);
    for (int i = 0; i < 4; ++i) {
        int X = r + dx[i];
        int Y = c + dy[i];
        res += floodfill(X, Y, c1, c2);
    }
    if (c == n - 1) {
        res += floodfill(r, 0, c1, c2);
    }
    if (c == 0) {
        res += floodfill(r, n - 1, c1, c2);
    }
    return res;
}

int main() {
    char land, water;
    while (scanf("%d %d\n", &m, &n) != EOF) {
        for (int i = 0; i < m; ++i) {
            gets(grid[i]);
        }
        scanf("%d %d", &x, &y);

        land = grid[x][y];
        water = '.';
        bool found = false;
        for (int i = 0; i < m && !found; ++i) {
            for (int j = 0; j < n && !found; ++j) {
                if (grid[i][j] != land) {
                    water = grid[i][j];
                    found = true;
                }
            }
        }

        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == land) {
                    res = max(res, floodfill(i, j, land, water));
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 15-Dec-2016
*/
