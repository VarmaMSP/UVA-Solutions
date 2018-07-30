#include <bits/stdc++.h>

using namespace std;

int p[110];
vector< tuple< int, int, int > > edge;

int find(int x) {
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main() {
    int tt, m, n, u, v, w, c = 1;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        while (m--) {
            scanf("%d %d %d", &u, &v, &w);
            edge.push_back({w, u, v});
        }
        sort(edge.rbegin(), edge.rend());
        int res = INT_MAX;
        for (auto e: edge) {
            int x = find(get<1>(e));
            int y = find(get<2>(e));
            if (x != y) {
                p[y] = x;
                res = min(res, get<0>(e));
            }
        }
        printf("Case #%d: %d\n", c++, res);
        edge.clear();
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 30-July-2018
*/
