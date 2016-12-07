#include <bits/stdc++.h>

using namespace std;

vector<int> dx, dy;
bool water[110][110], visit[110][110];
int grid[110][110], r, c;

void processDir(int m, int n) {
    dx.clear();
    dy.clear();
    if (m == 0 && n == 0) {
        dx.push_back(0);
        dy.push_back(0);
        return;
    }
    if (m == 0) {
        int x[] = {n, -n, 0,  0};
        int y[] = {0,  0, n, -n};
        dx.assign(x, x + 4);
        dy.assign(y, y + 4);
        return;
    }
    if (n == 0) {
        int x[] = {m, -m, 0,  0};
        int y[] = {0,  0, m, -m};
        dx.assign(x, x + 4);
        dy.assign(y, y + 4);
        return;
    }
    if (m == n) {
        int x[] = { m, m, -m, -m};
        int y[] = {-m, m, -m,  m};
        dx.assign(x, x + 4);
        dy.assign(y, y + 4);
        return;
    }
    if (m != n) {
        int x[] = {n, -n,  n, -n, m,  m, -m, -m};
        int y[] = {m,  m, -m, -m, n, -n,  n, -n};
        dx.assign(x, x + 8);
        dy.assign(y, y + 8);
        return;
    }
}

void DFS(int X, int Y) {
    visit[X][Y] = true;
    for (int i = 0; i < dx.size(); ++i) {
        int x = X + dx[i];
        int y = Y + dy[i];
        if (x >= 0 && x < r && y >= 0 && y < c && !water[x][y]) {
            grid[X][Y]++;
            if (!visit[x][y]) {
                DFS(x, y);
            }
        }
    }
}

int main() {
    int tt, m, n, w, x, y, k = 1;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d %d %d %d %d", &r, &c, &m, &n, &w);
        processDir(m, n);
        while (w--) {
            scanf("%d %d", &x, &y);
            water[x][y] = true;
        }
        if (!water[0][0]) {
            DFS(0, 0);
        }
        int even = 0, odd = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (visit[i][j]) {
                    if (grid[i][j] & 1)
                        ++odd;
                    else
                        ++even;
                }
            }
        }
        printf("Case %d: %d %d\n", k++, even, odd);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                water[i][j] = visit[i][j] = false;
                grid[i][j] = 0;
            }
        }
    }
    return 0;
}

/*
Author : bumpy (-_-)
date : 24-Jul-2016
*/
