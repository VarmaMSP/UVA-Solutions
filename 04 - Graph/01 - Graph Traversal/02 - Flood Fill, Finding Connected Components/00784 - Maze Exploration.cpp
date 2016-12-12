#include <bits/stdc++.h>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char grid[100][100];

void floodfill(int x, int y, char c1, char c2) {
    if (grid[x][y] != c1)
        return ;
    grid[x][y] = c2;
    for (int i = 0; i < 4; ++i) {
        int X = x + dx[i];
        int Y = y + dy[i];
        floodfill(X, Y, c1, c2);
    }
}

int main() {
    int tt;
    scanf("%d\n", &tt);
    while (tt--) {
        bool found = false;
        int x, y, m = 0;
        while (gets(grid[m]) && grid[m][0] != '_') {
            int n = strlen(grid[m]);
            for (int i = 0; i < n && !found; ++i) {
                if (grid[m][i] == '*') {
                    x = m;
                    y = i;
                    found = true;
                }
            }
            ++m;
        }
        grid[x][y] = ' ';
        floodfill(x, y, ' ', '#');
        for (int i = 0; i <= m; ++i) {
            puts(grid[i]);
        }
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 12-Dec-2016
*/

