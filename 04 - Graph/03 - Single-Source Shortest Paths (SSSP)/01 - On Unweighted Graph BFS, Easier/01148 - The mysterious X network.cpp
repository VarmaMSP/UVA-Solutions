#include <bits/stdc++.h>

using namespace std;

int d[100100];
bool visit[100100];
vector< int > G[100100];

void bfs(int s, int des) {
    queue< int > Q;
    d[s] = 0;
    visit[s] = true;
    Q.push(s);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (auto v: G[u]) if (!visit[v]) {
            visit[v] = true;
            d[v] = d[u] + 1;
            if (v == des) {
                return;
            } else {
                Q.push(v);
            }
        }
    }
}

int main() {
    int tt, n, c, u, v;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &u, &c);
            for (int j = 0; j < c; ++j) {
                scanf("%d", &v);
                G[u].push_back(v);
            }
        }
        scanf("%d %d", &u, &v);
        bfs(u, v);
        printf("%d %d %d\n", u, v, d[v] - 1);
        if (tt) puts("");
        for (int i = 0; i < n; ++i) {
            G[i].clear();
        }
        memset(visit, false, sizeof(visit));
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 22-Jul-2018
*/
