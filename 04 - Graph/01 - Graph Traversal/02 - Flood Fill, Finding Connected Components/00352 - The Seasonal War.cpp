#include <bits/stdc++.h>

using namespace std;

int n;
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
char grid[30][30];

void floodfill(int x, int y, char c1, char c2) {
    if (x < 0 || x >= n || y < 0 || y >= n)
        return ;
    if (grid[x][y] != c1)
        return ;
    grid[x][y] = c2;
    for (int i = 0; i < 8; ++i) {
        floodfill(x + dx[i], y + dy[i], c1, c2);
    }
}

int main() {
    int kk = 1;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i)
            scanf("%s", &grid[i]);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    floodfill(i, j, '1', '2');
                    cnt++;
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n", kk++, cnt);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 30-Jul-2016
*/
