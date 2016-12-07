#include <bits/stdc++.h>

using namespace std;

int m, n;
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
char grid[110][110];

void floodfill(int x, int y, char c1, char c2) {
    if (x < 0 || x >= m || y < 0 || y >= n)
        return ;
    if (grid[x][y] != c1)
        return ;
    grid[x][y] = c2;
    for (int i = 0; i < 8; ++i) {
        floodfill(x + dx[i], y + dy[i], c1, c2);
    }
}

int main(){
    while (scanf("%d %d", &m, &n) && m|n) {
        for (int i = 0; i < m; ++i) {
            scanf("%s", &grid[i]);
        }
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '@') {
                    floodfill(i, j, '@', '.');
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 30-Jul-2016
*/
