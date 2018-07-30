#include <bits/stdc++.h>

using namespace std;

typedef tuple< int, int, int > Ti3;

int c, p[220], g[220][220];
bool visit[220];
vector< Ti3 > edge;

int find(int x) {
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

bool dfs(int u, int des, int& res) {
    visit[u] = true;
    if (u == des) return true;
    for (int v = 0; v < c; ++v) if (g[u][v] && !visit[v]) {
        if (dfs(v, des, res)) {
            res = max(res, g[u][v]);
            return true;
        }
    }
    return false;
}

int main() {
    int s, q, u, v, w, ca = 1;
    bool firstLine = true;
    while (scanf("%d %d %d", &c, &s, &q) && (c|s|q)) {
        for (int i = 0; i < c; ++i) {
            p[i] = i;
        }
        while (s--) {
            scanf("%d %d %d", &u, &v, &w);
            edge.push_back({w, u - 1, v - 1});
        }
        sort(edge.begin(), edge.end());
        for (auto e: edge) {
            int x = find(get<1>(e));
            int y = find(get<2>(e));
            if (x != y) {
                p[y] = x;
                u = get<1>(e);
                v = get<2>(e);
                w = get<0>(e);
                g[u][v] = w;
                g[v][u] = w;
            }

        }
        if (!firstLine) puts("");
        printf("Case #%d\n", ca++);
        while (q--) {
            scanf("%d %d", &u, &v);
            int res = INT_MIN;
            if (dfs(u - 1, v - 1, res)) {
                printf("%d\n", res);
            } else {
                printf("no path\n");
            }
            memset(visit, false, sizeof(visit));
        }
        firstLine = false;
        edge.clear();
        memset(g, 0, sizeof(g));
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 30-July-2018
*/
