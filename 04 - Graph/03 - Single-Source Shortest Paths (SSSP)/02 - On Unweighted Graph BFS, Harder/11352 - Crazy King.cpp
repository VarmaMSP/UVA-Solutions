#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int > pii;

int dxk[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dyk[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dxh[] = {-2, -2, -1, 1, 2, 2, -1, 1};
int dyh[] = {-1, 1, 2, 2, -1, 1, -2, -2};
int m, n, d[110][110];
bool visit[110][110];
char g[110][110];

int bfs(pii s, pii des) {
    queue< pii > Q;
    int x = s.first;
    int y = s.second;
    d[x][y] = 0;
    visit[x][y] = true;
    Q.push(s);
    while (!Q.empty()) {
        pii u = Q.front(); Q.pop();
        x = u.first;
        y = u.second;
        if (u == des) return d[x][y];
        for (int i = 0; i < 8; ++i) {
            int X = dxk[i] + x;
            int Y = dyk[i] + y;
            if (0 <= X && X < m && 0 <= Y && Y < n && g[X][Y] != 'X' && !visit[X][Y]) {
                d[X][Y] = d[x][y] + 1;
                visit[X][Y] = true;
                Q.push({X, Y});
            }
        }
    }
    return -1;
}

int main() {
    int tt;
    pii a, b;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d %d", &m, &n);
        for (int i = 0; i < m; ++i) {
            scanf("%s", g[i]);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (g[i][j] == 'A') {
                    a = {i, j};
                }
                if (g[i][j] == 'B') {
                    b = {i, j};
                }
                if (g[i][j] == 'Z') {
                    g[i][j] = 'X';
                    for (int k = 0; k < 8; ++k) {
                        int x = dxh[k] + i;
                        int y = dyh[k] + j;
                        if (0 <= x && x < m && 0 <= y && y < n && g[x][y] == '.') {
                            g[x][y] = 'X';
                        }
                    }
                }
            }
        }
        int len = bfs(a, b);
        // Check you output in udebug before submiting.
        if (len != -1) printf("Minimal possible length of a trip is %d\n", len);
        if (len == -1) printf("King Peter, you can't go now!\n");
        memset(visit, false, sizeof(visit));
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 29-July-2018
*/
