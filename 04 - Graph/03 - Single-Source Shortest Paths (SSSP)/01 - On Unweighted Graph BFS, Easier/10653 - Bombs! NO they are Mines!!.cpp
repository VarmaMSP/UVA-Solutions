#include <bits/stdc++.h>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int r, c, G[1010][1010], d[1010][1010];
bool visit[1010][1010];

int bfs(pair< int, int > s, pair< int, int > des) {
    queue< pair< int, int > > Q;
    d[s.first][s.second] = 0;
    visit[s.first][s.second] = true;
    Q.push(s);
    while (!Q.empty()) {
        auto u = Q.front(); Q.pop();
        if (u == des) return d[u.first][u.second];
        for (int i = 0; i < 4; ++i) {
            int X = dx[i] + u.first;
            int Y = dy[i] + u.second;
            if (0 <= X && X < r && 0 <= Y && Y < c && !visit[X][Y] && !G[X][Y]) {
                d[X][Y] = d[u.first][u.second] + 1;
                visit[X][Y] = true;
                Q.push({X, Y});
            }
        }
    }
    return 0;
}

int main() {
    int x, y, br, bc;
    pair< int, int > s, d;
    while (scanf("%d %d", &r, &c) && (r|c)) {
        scanf("%d", &x);
        while (x--) {
            scanf("%d %d", &br, &y);
            while (y--) {
                scanf("%d", &bc);
                G[br][bc] = 1;
            }
        }
        scanf("%d %d", &s.first, &s.second);
        scanf("%d %d", &d.first, &d.second);
        printf("%d\n", bfs(s, d));
        memset(G, 0, sizeof(G));
        memset(visit, false, sizeof(visit));
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 27-July-2018
*/
