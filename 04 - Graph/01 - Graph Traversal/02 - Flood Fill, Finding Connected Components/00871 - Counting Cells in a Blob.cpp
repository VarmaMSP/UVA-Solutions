#include <bits/stdc++.h>

using namespace std;

int m, n;
char grid[110][110];
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int floodfill(int x, int y, char c1, char c2) {
    if (x < 0 || y < 0 || x >= m || y >= n)
        return 0;
    if (grid[x][y] != c1)
        return 0;
    grid[x][y] = c2;
    int res = 1;
    for (int i = 0; i < 8; ++i) {
        int X = x + dx[i];
        int Y = y + dy[i];
        res += floodfill(X, Y, c1, c2);
    }
    return res;
}

int main() {
    int tt;
    scanf("%d\n\n", &tt);
    while (tt--) {
        m = 0;
        while (gets(grid[m]) && grid[m][0])
            m++;
        n = strlen(grid[0]);
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1')
                    res = max(res, floodfill(i, j, '1', '0'));
            }
        }
        printf("%d\n", res);
        if (tt)
            printf("\n");
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 11-Dec-2016
*/
