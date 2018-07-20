#include <bits/stdc++.h>

using namespace std;

int p[1000100];
vector< tuple< int, int, int > > edge;

int find_set(int x) {
    if (p[x] != x)
        p[x] = find_set(p[x]);
    return p[x];
}

int main() {
    int n, u, v, w, k, m;
    bool firstLine = true;
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; ++i) {
            p[i] = i;
        }
        int original = 0;
        for (int i = 0; i < n - 1; ++i) {
            scanf("%d %d %d", &u, &v, &w);
            original += w;
        }
        scanf("%d", &k);
        while (k--) {
            scanf("%d %d %d", &u, &v, &w);
            edge.push_back({w, u, v});
        }
        scanf("%d", &m);
        while (m--) {
            scanf("%d %d %d", &u, &v, &w);
            edge.push_back({w, u, v});
        }
        sort(edge.begin(), edge.end());
        int res = 0;
        for (const auto& e: edge) {
            int x = find_set(get<1>(e));
            int y = find_set(get<2>(e));
            if (x != y) {
                p[x] = y;
                res += get<0>(e);
            }
        }
        if (!firstLine) printf("\n");
        printf("%d\n%d\n", original, res);
        firstLine = false;
        edge.clear();
    }
    return 0;
}
