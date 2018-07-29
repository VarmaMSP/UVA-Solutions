#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int n, d[20200];
vector< pii > G[20200];

int disjkra(int s, int des) {
    priority_queue< pii, vector< pii >, greater< pii > > Q;
    for (int i = 0; i < n; ++i) {
        d[i] = INT_MAX;
    }
    d[s] = 0;
    Q.push({d[s], s});
    while (!Q.empty()) {
        int u = Q.top().second; Q.pop();
        for (auto x: G[u]) {
            int w = x.first;
            int v = x.second;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                Q.push({d[v], v});
            }
        }
        if (u == des) return d[u];
    }
    return -1;
}

int main() {
    int tt, m, u, v, w, s, t, c = 1;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d %d %d %d", &n, &m, &s, &t);
        while (m--) {
            scanf("%d %d %d", &u, &v, &w);
            G[u].push_back({w, v});
            G[v].push_back({w, u});
        }
        int dis = disjkra(s, t);
        if (dis == -1) printf("Case #%d: unreachable\n", c++);
        if (dis != -1) printf("Case #%d: %d\n", c++, dis);
        for (int i = 0; i < n; ++i) {
            G[i].clear();
        }
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 29-July-2018
*/
