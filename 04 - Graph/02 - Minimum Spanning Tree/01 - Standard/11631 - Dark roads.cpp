#include <bits/stdc++.h>

using namespace std;

vector< tuple< int, int, int > > edge;
int p[200200];

int find_set(int x) {
    if (p[x] != x)
        p[x] = find_set(p[x]);
    return p[x];
}

int main() {
    int m, n, x, y, z;
    while (scanf("%d %d", &m, &n) && (m|n)) {
        for (int i = 0; i < m; ++i) {
            p[i] = i;
        }
        int t = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d %d %d", &x, &y, &z);
            edge.push_back({z, x, y});
            t += z;
        }
        sort(edge.begin(), edge.end());
        int res = 0;
        for (auto const& e: edge) {
            x = find_set(get<1>(e));
            y = find_set(get<2>(e));
            if (x != y) {
                p[y] = x;
                res += get<0>(e);
            }
        }
        printf("%d\n", t - res);
        edge.clear();
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 20-Jul-2018
*/
