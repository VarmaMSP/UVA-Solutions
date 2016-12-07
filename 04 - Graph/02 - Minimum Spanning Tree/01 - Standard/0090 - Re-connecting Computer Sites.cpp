#include <bits/stdc++.h>

using namespace std;

int p[1000100];
vector< pair< int, pair< int, int > > > edge;

int find_set(int x) {
    if (p[x] != x)
        p[x] = find_set(p[x]);
    return p[x];
}

int main() {
    int n, u, v, w, k, m;
    bool isFirstLine = true;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n - 1; ++i) {
            p[i + 1] = i + 1;
        }
        int original = 0;
        for (int i = 0; i < n - 1; ++i) {
            scanf("%d %d %d", &u, &v, &w);
            original += w;
        }
        scanf("%d", &k);
        for (int i = 0; i < k; ++i) {
            scanf("%d %d %d", &u, &v, &w);
            edge.push_back({w, {u, v}});
        }
        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d", &u, &v, &w);
            edge.push_back({w, {u, v}});
        }
        sort(edge.begin(), edge.end());
        int res = 0;
        for (const auto& e: edge) {
            int x = find_set(e.second.first);
            int y = find_set(e.second.second);
            if (x != y) {
                p[x] = y;
                res += e.first;
            }
        }
        if (!isFirstLine)
            printf("\n");
        else
            isFirstLine = !isFirstLine;
        printf("%d\n%d\n", original, res);
        edge.clear();
    }
    return 0;
}
