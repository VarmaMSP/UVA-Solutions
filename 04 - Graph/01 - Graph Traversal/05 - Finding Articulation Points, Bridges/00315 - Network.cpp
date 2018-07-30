#include <bits/stdc++.h>

using namespace std;

int cntr, cnt, low[110], num[110];
bool visit[110];
vector< int > G[110];

void dfs(int u, int p) {
    visit[u] = true;
    num[u] = low[u] = cntr++;
    int c = 0;
    bool isArtPnt = false;
    for (auto v: G[u]) {
        if (!visit[v]) {
            c += 1;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= num[u]) isArtPnt = true;
        }
        if (visit[v] && v != p) {
            low[u] = min(low[u], num[v]);
        }
    }
    if (u == p && c == 1) isArtPnt = false;
    cnt += isArtPnt;
}

int main() {
    int n, u, v;
    string str;
    while (cin >> n && n) {
        while (getline(cin, str) && str != "0") {
            stringstream ss(str);
            ss >> u;
            while (ss >> v) {
                G[u - 1].push_back(v - 1);
                G[v - 1].push_back(u - 1);
            }
        }
        cntr = cnt = 0;
        dfs(0, 0);
        printf("%d\n", cnt);
        for (int i = 0; i < n; ++i) {
            G[i].clear();
        }
        memset(visit, false, sizeof(visit));
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 30-July-2018
*/
