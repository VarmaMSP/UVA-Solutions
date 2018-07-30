#include <bits/stdc++.h>

using namespace std;

int p[10100];
vector< tuple< int, int, int > > edges;

int find(int x) {
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main() {
    int tt, n, m, u, v, w;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        while (m--) {
            scanf("%d %d %d", &u, &v, &w);
            edges.push_back({w, u - 1, v - 1});
        }
        sort(edges.rbegin(), edges.rend());
        int res = 0;
        for (auto e: edges) {
            int x = find(get<1>(e));
            int y = find(get<2>(e));
            if (x != y) {
                p[y] = x;
            } else {
                res += get<0>(e);
            }
        }
        printf("%d\n", res);
        edges.clear();
    }
    scanf("%d", &tt);
    return 0;
}

/*
Author: bumpy (-_-)
date: 30-July-2018
*/
