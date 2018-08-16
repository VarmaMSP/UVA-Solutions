#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int > pii;

int n, g[500][500], d[500];
vector< int > p[500];

void dijkstra(int s) {
    priority_queue< pii, vector< pii >, greater< pii > > Q;
    for (int i = 0; i < n; ++i) {
        d[i] = INT_MAX;
    }
    d[s] = 0;
    Q.push({d[s], s});
    while (!Q.empty()) {
        int u = Q.top().second; Q.pop();
        for (int v = 0; v < n; ++v) if (g[u][v] != INT_MAX) {
            if (d[v] > d[u] + g[u][v]) {
                p[v].clear();
                p[v].push_back(u);
                d[v] = d[u] + g[u][v];
                Q.push({d[v], v});
            } else if (d[v] == d[u] + g[u][v]) {
                p[v].push_back(u);
            }
        }
    }
}

void removePathTo(int u) {
    for (auto v: p[u]) {
        g[v][u] = INT_MAX;
        removePathTo(v);
    }
}

int main() {
    int m, src, des, u, v, w;
    while (scanf("%d %d", &n, &m) && (n|m)) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                g[i][j] = INT_MAX;
            }
        }
        scanf("%d %d", &src, &des);
        while (m--) {
            scanf("%d %d %d", &u, &v, &w);
            g[u][v] = w;
        }
        dijkstra(src);
        removePathTo(des);
        dijkstra(src);
        printf("%d\n", d[des] != INT_MAX ? d[des] : -1);
        for (int i = 0; i < n; ++i) {
            p[i].clear();
        }
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 16-Aug-2018
*/
