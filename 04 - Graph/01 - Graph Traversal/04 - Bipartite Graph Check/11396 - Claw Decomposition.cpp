#include <bits/stdc++.h>

using namespace std;

vector<int> G[400];
int color[400];

bool BFS(int s) {
    queue<int> Q;
    Q.push(s);
    color[s] = 1;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (auto v: G[u]) {
            if (color[u] == color[v]) {
                return false;
            }
            if (color[v] == 0) {
                color[v] = -color[u];
                Q.push(v);
            }
        }
    }
    return true;
}

int main() {
    int n, u, v;
    while (scanf("%d", &n) && n) {
        while (scanf("%d %d", &u, &v) && u|v) {
            --u, --v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        bool isbipart = true;
        for (int i = 0; i < n; ++i) {
            if(!color[i]) {
                isbipart = BFS(i);
            }
        }
        printf(isbipart ? "YES\n" : "NO\n");
        for (int i = 0; i < n; ++i)
            G[i].clear();
        memset(color, 0, sizeof(color));
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 1-Aug-2016
*/
