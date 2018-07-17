#include <bits/stdc++.h>

using namespace std;

vector< int > G[2020], GT[2020];
bool visit[2020];
int s;

void DFS1(int u) {
    visit[u] = true;
    for (auto v: G[u]) if (!visit[v]) {
        DFS1(v);
    }
    s = u;
}

void DFS2(int u) {
    visit[u] = true;
    for (auto v: GT[u]) if (!visit[v]) {
        DFS2(v);
    }
}

int main() {
    int n, m, u, v, p;
    while (scanf("%d %d", &n, &m) && (n|m)) {
        while (m--) {
            scanf("%d %d %d", &u, &v, &p); --u, --v;
            G[u].push_back(v);
            GT[v].push_back(u);
            if (p == 2) {
                G[v].push_back(u);
                GT[u].push_back(v);
            }
        }
        for (int u = 0; u < n; ++u) {
            if (!visit[u]) {
                DFS1(u);
            }
        }
        memset(visit, false, sizeof(visit)), DFS2(s);
        bool isConn = true;
        for (int u = 0; u < n && isConn; ++u) {
            if (!visit[u]) isConn = false;
        }
        puts(isConn ? "1" : "0");
        for (int i = 0; i < n; ++i) {
            G[i].clear();
            GT[i].clear();
        }
        memset(visit, false, sizeof(visit));
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 17-Jul-2018
*/
