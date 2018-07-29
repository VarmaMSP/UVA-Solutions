#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int > pii;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int r, c, d[1010][1010];
bool visit[1010][1010];
char g[1010][1010];

void bfs() {
    pii p;
    queue< pii > Q;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (g[i][j] == 'F') {
                d[i][j] = 0;
                visit[i][j] = true;
                Q.push({i, j});
            }
            if (g[i][j] == 'J') {
                d[i][j] = 0;
                visit[i][j] = true;
                p = {i, j};
            }
        }
    }
    Q.push(p);
    while (!Q.empty()) {
        pii u = Q.front(); Q.pop();
        for (int i = 0; i < 4; ++i) {
            int X = dx[i] + u.first;
            int Y = dy[i] + u.second;
            if (0 <= X && X < r && 0 <= Y && Y < c && g[X][Y] != '#' && !visit[X][Y]) {
                d[X][Y] = d[u.first][u.second] + 1;
                visit[X][Y] = true;
                Q.push({X, Y});
                g[X][Y] = g[u.first][u.second];

            }
        }
    }
}

int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d %d", &r, &c);
        for (int i = 0; i < r; ++i) {
            scanf("%s", g[i]);
        }
        bfs();
        int time = INT_MAX;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (g[i][j] == 'J' && (i == 0 || j == 0 || i == r - 1 || j == c - 1)) {
                    time = min(d[i][j], time);
                }
            }
        }
        if (time < INT_MAX)  printf("%d\n", time + 1);
        if (time == INT_MAX) printf("IMPOSSIBLE\n");
        memset(visit, false, sizeof(visit));
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 28-July-2018
*/
