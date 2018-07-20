#include <bits/stdc++.h>

using namespace std;

int p[1010];
vector< tuple< int, int, int > > edge;

int find_set(int x) {
    if (p[x] != x)
        p[x] = find_set(p[x]);
    return p[x];
}

int main() {
    int n, m, u, v, w;
    while (scanf("%d %d", &n, &m) && (n|m)) {
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        while (m--) {
            scanf("%d %d %d", &u, &v, &w);
            edge.push_back({w, u, v});
        }
        sort(edge.begin(), edge.end());
        bool isForest = true, flag = true;
        for (auto const& e: edge) {
            int x = find_set(get<1>(e));
            int y = find_set(get<2>(e));
            if (x != y) {
                p[y] = x;
            } else {
                if (!flag) printf(" ");
                printf("%d", get<0>(e));
                isForest = false;
                flag = false;
            }
        }
        if (isForest) printf("forest");
        printf("\n");
        edge.clear();
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 20-Jul-2018
*/
