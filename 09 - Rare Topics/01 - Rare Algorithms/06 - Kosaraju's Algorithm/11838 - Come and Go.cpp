#include <bits/stdc++.h>

using namespace std;

int s;
bool visit[2020];
vector< int > G[2020], GT[2020];

void DFS1(int u) {
    visit[u] = true;
    for (auto v: G[u]) {
        if (!visit[v]) {
            DFS1(v);
        }
    }
    s = u;
}

void DFS2(int u) {
    visit[u] = true;
    for (auto v: GT[u]) {
        if (!visit[v]) {
            DFS2(v);
        }
    }
}

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) && (n|m)) {
        while (m--) {
            int u, v, p;
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
        memset(visit, false, sizeof(visit));
        DFS2(s);
        bool flag = true;
        for (int u = 0; u < n; ++u) {
            if (!visit[u]) {
                flag = false;
                break;
            }
        }
        puts(flag ? "1" : "0");
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
date: 23-Aug-2018
*/
