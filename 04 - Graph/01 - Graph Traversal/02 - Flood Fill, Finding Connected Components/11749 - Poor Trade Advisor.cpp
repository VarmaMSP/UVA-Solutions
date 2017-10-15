#include <bits/stdc++.h>

using namespace std;

vector< pair< int, int > > G[550];
bool visit[550];

void dfs(int u, int maxPPA, set<int> &cities) {
    visit[u] = true;
    for (auto &x: G[u]) {
        int v   = x.second;
        int ppa = x.first;
        if (!visit[v] && ppa == maxPPA) {
            dfs(v, maxPPA, cities);
            cities.insert(u);
            cities.insert(v);
        }
    }
}

int main() {
    int m, n;
    while (scanf("%d %d", &n, &m) && (n | m)) {
        int u, v, ppa, maxPPA = INT_MIN;
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d", &u, &v, &ppa);
            G[u].push_back({ppa, v});
            G[v].push_back({ppa, u});
            maxPPA = max(maxPPA, ppa);
        }

        //result = max(size of all cc's with each edge having a ppa equal to maxPPA)
        int maxCount = -1;
        for (int i = 1; i < n; ++i) {
            if (!visit[i]) {
                set<int> cities;
                dfs(i, maxPPA, cities);
                maxCount = max(maxCount, (int)cities.size());
            }
        }
        printf("%d\n", maxCount);

        for (int i = 0; i < 550; ++i) {
            G[i].clear();
            visit[i] = false;
        }
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 15-Oct-2017
*/
