#include <bits/stdc++.h>

using namespace std;

int n, p[220], G[220][220];
bool visit[220];
vector< tuple< int, int > > node;
vector< tuple< int, int, int > > edge;

int find_set(int x) {
    if (p[x] != x)
        p[x] = find_set(p[x]);
    return p[x];
}

bool dfs(int u, int& res) {
    visit[u] = true;
    if (u == 1) return true;
    for (int v = 0; v < n; ++v) if (G[u][v] && !visit[v]){
        if (dfs(v, res)) {
            res = max(res, G[u][v]);
            return true;
        }
    }
    return false;
}

int main() {
    int x, y, c = 1;
    while (scanf("%d", &n) && n) {
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &x, &y);
            node.push_back({x, y});
            p[i] = i;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int a = get<0>(node[i]) - get<0>(node[j]);
                int b = get<1>(node[i]) - get<1>(node[j]);
                edge.push_back({a * a + b * b, i, j});
            }
        }
        sort(edge.begin(), edge.end());
        for (auto const& e: edge) {
            x = find_set(get<1>(e));
            y = find_set(get<2>(e));
            if (x != y) {
                p[y] = x;
                G[get<1>(e)][get<2>(e)] = get<0>(e);
                G[get<2>(e)][get<1>(e)] = get<0>(e);
            }
        }
        int res = -1;
        dfs(0, res);
        printf("Scenario #%d\n", c++);
        printf("Frog Distance = %.3f\n", sqrt(res));
        printf("\n");
        node.clear();
        edge.clear();
        memset(G, 0, sizeof(G));
        memset(visit, false, sizeof(visit));
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 20-Jul-2018
*/
