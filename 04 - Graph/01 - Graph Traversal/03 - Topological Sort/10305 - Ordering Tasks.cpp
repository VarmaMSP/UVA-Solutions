#include <bits/stdc++.h>

using namespace std;

vector< int > G[110], S;
bool visit[110];

void DFS(int u) {
    visit[u] = true;
    for (auto v: G[u]) {
        if (!visit[v]) {
            DFS(v);
        }
    }
    S.push_back(u);
}

int main() {
    int n, m, u, v;
    while (scanf("%d %d", &n, &m) && n|m) {
        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &u, &v);
            G[v].push_back(u);
        }
        for (int i = 1; i <= n; ++i) {
            if (!visit[i]) {
                DFS(i);
            }
        }
        for (auto x: S) {
            printf ("%d ", x);
        }
        printf("\n");

        memset(visit, false, sizeof(visit));
        for (int i = 1; i <= n; ++i)
            G[i].clear();
        S.clear();
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 12-Dec-2016
*/
