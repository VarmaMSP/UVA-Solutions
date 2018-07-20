#include <bits/stdc++.h>

using namespace std;

int n, p[220], G[220][220];
bool visit[220];
map< string, int > nameId;
vector< tuple< int, int, int > > edge;

int find_set(int x) {
    if (p[x] != x)
        p[x] = find_set(p[x]);
    return p[x];
}

bool dfs(int u, int des, int& res) {
    visit[u] = true;
    if (u == des) return true;
    for (int v = 1; v <= n; ++v) if (G[u][v] && !visit[v]) {
        if (dfs(v, des, res)) {
            res = min(res, G[u][v]);
            return true;
        }
    }
    return false;
}

int main() {
    int r, w, c = 1;
    string s, t;
    while (cin >> n >> r && (n|r)) {
        int id = 1;
        while (r--) {
            cin >> s >> t >> w;
            if (nameId[s] == 0) nameId[s] = p[id] = id, id += 1;
            if (nameId[t] == 0) nameId[t] = p[id] = id, id += 1;
            edge.push_back({w, nameId[s], nameId[t]});
        }
        cin >> s >> t;
        sort(edge.rbegin(), edge.rend());
        for (auto const& e: edge) {
            int x = find_set(get<1>(e));
            int y = find_set(get<2>(e));
            if (x != y) {
                p[y] = x;
                G[get<1>(e)][get<2>(e)] = get<0>(e);
                G[get<2>(e)][get<1>(e)] = get<0>(e);
            }
        }
        int res = INT_MAX;
        dfs(nameId[s], nameId[t], res);
        printf("Scenario #%d\n", c++);
        printf("%d tons\n", res);
        printf("\n");
        edge.clear();
        nameId.clear();
        memset(G, 0, sizeof(G));
        memset(visit, false, sizeof(visit));
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 20-Jul-2018
*/
