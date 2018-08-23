#include <bits/stdc++.h>

using namespace std;

int d[110];
vector< pair< int, int > > G[1010];

int main() {
    int tt, n, m, x, y, z;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d %d", &n, &m);
        while (m--) {
            scanf("%d %d %d", &x, &y, &z);
            G[x].push_back({z, y});
        }
        for (int i = 0; i < n; ++i) {
            d[i] = INT_MAX;
        }
        d[0] = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int u = 0; u < n; ++u) {
                for (auto p: G[u]) {
                    int v = p.second;
                    int t = p.first;
                    d[v] = min(d[v], d[u] + t);
                }
            }
        }
        bool isPoss = false;
        for (int u = 0; u < n; ++u) {
            for (auto p: G[u]) {
                int v = p.second;
                int t = p.first;
                if (d[v] > d[u] + t) {
                    isPoss = true;
                    break;
                }
            }
        }
        puts(isPoss ? "possible" : "not possible");
        for (int i = 0; i < n; ++i) {
            G[i].clear();
        }
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 23-Aug-2018
*/
