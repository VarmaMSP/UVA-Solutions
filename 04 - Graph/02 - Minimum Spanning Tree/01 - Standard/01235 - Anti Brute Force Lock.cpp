#include <bits/stdc++.h>

using namespace std;

int p[550];
vector< tuple< int, int, int > > edge;

inline int rolls(int x, int y) {
    return min(abs(x - y), 10 - abs(x - y));
}

int find_set(int x) {
    if (p[x] != x)
        p[x] = find_set(p[x]);
    return p[x];
}

int main() {
    int tt, n, k[550];
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d", &n);
        int firstRoll = INT_MAX;
        for (int i = 0; i < n; ++i) {
            scanf("%d", k + i), p[i] = i;
            int x = k[i];
            int r = 0;
            while (x) {
                r += rolls(0, x % 10);
                x /= 10;
            }
            firstRoll = min(firstRoll, r);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int x = k[i];
                int y = k[j];
                int r = 0;
                while (x || y) {
                    r += rolls(x % 10, y % 10);
                    x /= 10, y /= 10;
                }
                edge.push_back({r, i, j});
            }
        }
        sort(edge.begin(), edge.end());
        int res = 0;
        for (auto const& e: edge) {
            int x = find_set(get<1>(e));
            int y = find_set(get<2>(e));
            if (x != y) {
                p[y] = x;
                res += get<0>(e);
            }
        }
        printf("%d\n", firstRoll + res);
        edge.clear();
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 20-Jul-2018
*/
