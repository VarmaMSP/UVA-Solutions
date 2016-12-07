#include <bits/stdc++.h>

using namespace std;

vector<int> G[300];
int color[300], res;

bool BFS(int s) {
    queue<int> Q;
    int c1 = 0, c2 = 0;
    bool isbipart = true;
    Q.push(s);
    color[s] = 1;
    while (!Q.empty()){
        int u = Q.front();
        Q.pop();
        if (color[u] ==  1) c1++;
        if (color[u] == -1) c2++;
        for (auto v: G[u]){
            if (color[u] == color[v]) {
                isbipart = false;
            }
            if (color[v] == 0) {
                color[v] = -color[u];
                Q.push(v);
            }
        }
    }
    if (isbipart) {
        res += (min(c1, c2) == 0 ? 1 : min(c1, c2));
    }
    return isbipart;
}

int main() {
    int tt, m, n, u, v;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d %d", &n, &m);
        while (m--) {
            scanf("%d %d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        res = 0;
        bool isBipart = true;
        for (int i = 0; i < n && isBipart; ++i) {
            if (!color[i]) {
                isBipart = BFS(i);
            }
        }
        if (isBipart)
            printf("%d\n", res);
        else
            printf("-1\n");
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
