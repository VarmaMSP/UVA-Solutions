#include <bits/stdc++.h>

using namespace std;

int p[30];
vector< tuple< int, int, int > > edge;

int find_set(int x) {
    if (p[x] != x)
        p[x] = find_set(p[x]);
    return p[x];
}

int main() {
    int tt, n, s, c = 1;
    char cha;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            for (int j = 0; j < n; ++j) {
                scanf("%d%c", &s, &cha);
                if (i < j && s > 0) {
                    edge.push_back({s, i, j});
                }
            }
        }
        sort(edge.begin(), edge.end());
        printf("Case %d:\n", c++);
        for (auto const& e: edge) {
            int x = find_set(get<1>(e));
            int y = find_set(get<2>(e));
            if (x != y) {
                p[y] = x;
                printf("%c-%c %d\n", 'A' + get<1>(e), 'A' + get<2>(e), get<0>(e));
            }
        }
        edge.clear();
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 20-Jul-2018
*/
