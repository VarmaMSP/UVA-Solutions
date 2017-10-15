#include <bits/stdc++.h>

using namespace std;

int n, m;
char grid[100][100];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void fillDot(int x, int y, char c1, char c2) {
    if (x < 0 || x >= m || y < 0 || y >= n)
        return ;
    if (grid[x][y] != c1)
        return ;
    grid[x][y] = c2;
    for (int i = 0; i < 4; ++i) {
        fillDot(x + dx[i], y + dy[i], c1, c2);
    }
}

int fillDie(int x, int y, char c1, char c2) {
    if (x < 0 || x >= m || y < 0 || y >= n)
        return 0;
    if (grid[x][y] == c2)
        return 0;
    int dot = 0;
    if (grid[x][y] == 'X') {
        fillDot(x, y, 'X', '*');
        dot++;
    }
    grid[x][y] = c2;
    for (int i = 0; i < 4; ++i) {
        dot += fillDie(x + dx[i], y + dy[i], c1, c2);
    }
    return dot;
}

int main() {
    int kk = 1;
    while (scanf("%d %d", &n, &m) && n|m) {
        for (int i = 0; i < m; ++i) {
            scanf("%s", &grid[i]);
        }
        vector<int> die;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '*') {
                    die.push_back(fillDie(i, j, '*', '.'));
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'X') {
                    die.push_back(1);
                    fillDot(i, j, 'X', '.');
                }
            }
        }
        sort(die.begin(), die.end());
        printf("Throw %d\n", kk++);
        for (int i = 0; i < die.size(); ++i) {
            if (i > 0) {
                printf(" ");
            }
            printf("%d", die[i]);
        }
        printf("\n\n");
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 30-Jul-2016
*/
