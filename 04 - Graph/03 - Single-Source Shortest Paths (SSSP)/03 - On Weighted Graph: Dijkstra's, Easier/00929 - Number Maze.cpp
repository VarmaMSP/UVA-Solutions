#include <bits/stdc++.h>

using namespace std;

typedef tuple< int, int, int > Ti3;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int m, n, g[1000][1000], d[1000][1000];

int disjkra() {
    priority_queue< Ti3, vector< Ti3 >, greater< Ti3 > > Q;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            d[i][j] = INT_MAX;
        }
    }
    d[0][0] = g[0][0];
    Q.push({d[0][0], 0, 0});
    while (!Q.empty()) {
        Ti3 u = Q.top(); Q.pop();
        int x = get<1>(u);
        int y = get<2>(u);
        for (int i = 0; i < 4; ++i) {
            int X = dx[i] + x;
            int Y = dy[i] + y;
            if (0 <= X && X < m && 0 <= Y && Y < n) {
                if (d[X][Y] > d[x][y] + g[X][Y]) {
                    d[X][Y] = d[x][y] + g[X][Y];
                    Q.push({d[X][Y], X, Y});
                }
            }
        }
    }
    return d[m - 1][n - 1];
}

int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d %d", &m, &n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", g[i] + j);
            }
        }
        printf("%d\n", disjkra());
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 29-July-2018
*/
