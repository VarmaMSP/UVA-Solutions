#include <bits/stdc++.h>

using namespace std;

vector<int> G[250];
int color[250];

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
    int n, l, u, v;
    while (scanf("%d", &n) && n) {
        scanf("%d", &l);
        while (l--) {
            scanf("%d %d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        bool bicolor = true;
        for (int i = 0; i < n && bicolor; ++i) {
            if (!color[i]) {
                bicolor = BFS(i);
            }
        }
        printf(bicolor ? "BICOLORABLE.\n" : "NOT BICOLORABLE.\n");
        for(int i = 0; i < n; ++i) {
            G[i].clear();
        }
        memset(color, 0, sizeof(color));
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 31-Jul-2016
*/
