#include <bits/stdc++.h>

using namespace std;

int cntr, num[1010], low[1010];
bool visit[1010];
vector< int > G[1010];
vector< pair< int, int > > edge;

void dfs(int u, int p) {
    visit[u] = true;
    num[u] = low[u] = cntr++;
    for (auto v: G[u]) {
        if (!visit[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            edge.push_back({u + 1, v + 1});
            if (low[v] > num[u]) {
                edge.push_back({v + 1, u + 1});
            }
        } else if (v != p) {
            low[u] = min(low[u], num[v]);
            if (num[u] > num[v]) { // distinguish back edge from forward edge
                edge.push_back ({u + 1, v + 1});
            }
        }
    }
}

int main() {
    int n, m, u, v, c = 1;
    while (scanf("%d %d", &n, &m) && (n|m)) {
        while (m--) {
            scanf("%d %d", &u, &v);
            G[u - 1].push_back(v - 1);
            G[v - 1].push_back(u - 1);
        }
        cntr = 0;
        dfs(0, 0);
        sort(edge.begin(), edge.end());
        printf("%d\n\n", c++);
        for (auto e: edge) {
            printf("%d %d\n", e.first, e.second);
        }
        printf("#\n");
        memset(visit, false, sizeof(visit));
        for (int i = 0; i < n; ++i) {
            G[i].clear();
        }
        edge.clear();
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 31-July-2018
*/
