#include <bits/stdc++.h>

using namespace std;

vector<int> G[10010];
bool visit[10010];

int dfs(int u) {
    visit[u] = true;
    int c = 1;
    for (int v: G[u]) {
        if (!visit[v]) {
            c += dfs(v);
        }
    }
    return c;
}

int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        int n, m, l;
        scanf("%d %d %d", &n, &m, &l);
        while (m--) {
            int u, v; //each domino can tip more than one domino
            scanf("%d %d", &u, &v);
            G[u].push_back(v);
        }

        int totalFell = 0;
        while (l--) {
            int u;
            scanf("%d", &u);
            if (!visit[u]) {
                totalFell += dfs(u);
            }
        }
        printf("%d\n", totalFell);

        for (int i = 1; i <= n; ++i) {
            G[i].clear();
        }
        memset(visit, false, sizeof(visit));
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 16-Oct-2017
*/
