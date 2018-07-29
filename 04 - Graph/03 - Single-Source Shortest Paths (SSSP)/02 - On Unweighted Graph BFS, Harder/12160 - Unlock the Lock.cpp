#include <bits/stdc++.h>

using namespace std;

int r, b[10], d[10000];
bool visit[10000];

int bfs(int s, int des) {
    queue< int > Q;
    d[s] = 0;
    visit[s] = true;
    Q.push(s);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int i = 0; i < r; ++i) {
            int v = (u + b[i]) % 10000;
            if (!visit[v]) {
                d[v] = d[u] + 1;
                visit[v] = true;
                Q.push(v);
            }
        }
        if (u == des) {
            return d[u];
        }
    }
    return -1;
}

int main() {
    int l, u, c = 1 ;
    while (scanf("%d %d %d", &l, &u, &r) && (l|u|r)) {
        for (int i = 0; i < r; ++i) {
            scanf("%d", b + i);
        }
        int presses = bfs(l, u);
        if (presses == -1) printf("Case %d: Permanently Locked\n", c++);
        if (presses != -1) printf("Case %d: %d\n", c++, presses);
        memset(visit, false, sizeof(visit));
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 28-July-2018
*/
