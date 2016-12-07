#include <bits/stdc++.h>

using namespace std;

char grid[220][220], X[220][220];
int compId[220][220], n;
int dx[] = {-1, -1, 0, 0, 1, 1};
int dy[] = {-1, 0, -1, 1, 0, 1};

void floodfill(int x, int y, char c1, char c2, int id) {
    if (x < 0 || x >= n || y < 0 || y >= n)
        return ;
    if (X[x][y] != c1)
        return ;
    X[x][y] = c2;
    compId[x][y] = id;
    for (int i = 0; i < 6; ++i) {
        floodfill(x + dx[i], y + dy[i], c1, c2, id);
    }
}

int main() {
    int kk = 1;
    while (scanf("%d", &n) && n){
        for (int i = 0; i < n; ++i)
            scanf("%s", &grid[i]);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                X[i][j] = grid[i][j];
            }
        }

        int id = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (X[i][j] != '0')
                    floodfill(i, j, X[i][j], '0', id++);
            }
        }
        char winner;
        bool found = false;
        for (int i = 0; i < n && !found; ++i) {
            for (int j = 0; j < n && !found; ++j) {
                if (grid[0][i] == 'b' && grid[n-1][j] == 'b' &&
                    compId[0][i] == compId[n-1][j]) {
                    winner = 'B';
                    found = true;
                }
                if (grid[i][0] == 'w' && grid[j][n-1] == 'w' &&
                    compId[i][0] == compId[j][n-1]) {
                    winner = 'W';
                    found = true;
                }
            }
        }
        printf("%d %c\n", kk++, winner);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 30-Jul-2016
*/
