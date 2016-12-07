#include <bits/stdc++.h>

using namespace std;

vector<int> G[300];
int color[300];

int BFS(int s) {
    queue<int> Q;
    Q.push(s);
    bool isbipart = true;
    int c1 = 0, c2 = 0;
    color[s] = 1;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        if (color[u] ==  1) c1++;
        if (color[u] == -1) c2++;
        for (auto v: G[u]) {
            if (color[v] == color[u]) {
                isbipart = false;
            }
            if (color[v] == 0) {
                color[v] = -color[u];
                Q.push(v);
            }
        }
    }
    return isbipart ? max(c1, c2) : 0;
}

int main() {
    int tt, n, m, v;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &m);
            while (m--) {
                scanf("%d", &v); v--;
                if (v >= 0 && v < n) {
                    G[i].push_back(v);
                    G[v].push_back(i);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (!color[i]) {
                res += BFS(i);
            }
        }
        printf("%d\n", res);

        for (int i = 0; i < n; ++i)
            G[i].clear();
        memset(color, 0, sizeof(color));
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 31-Jul-2016
*/
