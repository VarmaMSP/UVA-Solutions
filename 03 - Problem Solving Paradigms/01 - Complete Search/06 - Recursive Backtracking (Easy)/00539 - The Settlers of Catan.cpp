#include <bits/stdc++.h>

using namespace std;

int n, G[26][26];

int dfs(int u) {
    int d = 0;
    for (int v = 0; v < n; ++v) if (G[u][v]) {
        G[u][v] = G[v][u] = 0;
        d = max(d, 1 + dfs(v));
        G[u][v] = G[v][u] = 1;
    }
    return d;
}

int main() {
    int m, u, v;
    while (scanf("%d %d", &n, &m) && (n | m)) {
        while (m--) {
            scanf("%d %d", &u, &v);
            G[u][v] = G[v][u] = 1;
        }
        int res = INT_MIN;
        for (int i = 0; i < n; ++i) {
            res = max(res, dfs(i));
        }
        printf("%d\n", res);
        memset(G, 0, sizeof(G));
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 10-July-2018
*/
