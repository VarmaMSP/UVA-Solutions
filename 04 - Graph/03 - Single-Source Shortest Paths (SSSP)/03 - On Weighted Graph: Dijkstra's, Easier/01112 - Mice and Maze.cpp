#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int > pii;

int n, d[110];
vector< pii > G[110];

void disjkra(int s) {
    priority_queue< pii, vector< pii >, greater< pii > > Q;
    for (int i = 0; i < n; ++i) {
        d[i] = INT_MAX;
    }
    d[s] = 0;
    Q.push({d[s], s});
    while (!Q.empty()) {
        int u = Q.top().second; Q.pop();
        for (auto x: G[u]) {
            int v = x.second;
            int w = x.first;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                Q.push({d[v], v});
            }
        }
    }
}

int main() {
    int tt, e, t, m, u, v, w;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d %d %d %d", &n, &e, &t, &m);
        while (m--) {
            scanf("%d %d %d", &u, &v, &w);
            G[v - 1].push_back({w, u - 1});
        }
        disjkra(e - 1);
        int escaped = 0;
        for (int i = 0; i < n; ++i) {
            if (d[i] <= t) escaped += 1;
        }
        printf("%d\n", escaped);
        if (tt) puts("");
        for (int i = 0; i < n; ++i) {
            G[i].clear();
        }
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 30-July-2018
*/
