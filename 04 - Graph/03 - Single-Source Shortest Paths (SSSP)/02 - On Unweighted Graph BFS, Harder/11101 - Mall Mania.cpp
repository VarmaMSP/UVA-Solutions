#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int > pii;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int d[2020][2020];
bool visit[2020][2020];
vector< pii > m1, m2;

void bfs() {
    int x, y;
    queue< pii > Q;
    for (auto m: m1) {
        x = m.first;
        y = m.second;
        d[x][y] = 0;
        visit[x][y] = true;
        Q.push({x, y});
    }
    while (!Q.empty()) {
        pii u = Q.front(); Q.pop();
        x = u.first;
        y = u.second;
        for (int i = 0; i < 4; ++i) {
            int X = dx[i] + x;
            int Y = dy[i] + y;
            if (0 <= X && X <= 2000 && 0 <= Y && Y <= 2000 && !visit[X][Y]) {
                d[X][Y] = d[x][y] + 1;
                visit[X][Y] = true;
                Q.push({X, Y});
            }
        }
    }
}

int main() {
    int p, u, v;
    while (scanf("%d", &p) && p) {
        while (p--) {
            scanf("%d %d", &u, &v);
            m1.push_back({u, v});
        }
        scanf("%d", &p);
        while (p--) {
            scanf("%d %d", &u, &v);
            m2.push_back({u, v});
        }
        bfs();
        int minDis = INT_MAX;
        for (auto m: m2) {
            u = m.first;
            v = m.second;
            minDis = min(minDis, d[u][v]);
        }
        printf("%d\n", minDis);
        m1.clear();
        m2.clear();
        memset(visit, false, sizeof(visit));
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 29-July-2018
*/
