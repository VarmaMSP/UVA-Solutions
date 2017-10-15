#include <bits/stdc++.h>

using namespace std;

vector< pair< int, int > > G[550];
bool visit[550];

int bfs(int U, int maxPPA) {
    queue<int> Q;
    int count = 0;
    Q.push(U);
    visit[U] = true;
    while (!Q.empty()) {
        count += 1;
        int u = Q.front(); Q.pop();
        for (auto &x: G[u]) {
            int v = x.first;
            int ppa = x.second;
            if (!visit[v] && ppa == maxPPA) {
                Q.push(v);
                visit[v] = true;
            }
        }
    }
    return count;
}

int main() {
    int m, n;
    while (scanf("%d %d", &n, &m) && (n | m)) {
        int u, v, ppa, maxPPA = INT_MIN;
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d", &u, &v, &ppa);
            G[u].push_back({v, ppa});
            G[v].push_back({u, ppa});
            maxPPA = max(maxPPA, ppa);
        }

        //result = max(size of all cc's with each edge having a ppa equal to maxPPA)
        int maxCount = -1;
        for (int i = 1; i < n; ++i) {
            if (!visit[i]) {
                maxCount = max(maxCount, bfs(i, maxPPA));
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
