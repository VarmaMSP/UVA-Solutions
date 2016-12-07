#include <bits/stdc++.h>

using namespace std;

vector<int> G[110];
bool visit[110];

int DFS(int u) {
    int cnt = 0;
    for (auto v: G[u]) {
        if (!visit[v]) {
            visit[v] = true;
            cnt += (1 + DFS(v));
        }
    }
    return cnt;
}

int main() {
    int n;
    while (scanf("%d", &n) && n) {
        int u, v;
        while (scanf("%d", &u) && u) {
            while (scanf("%d", &v) && v) {
                G[u].push_back(v);
            }
        }
        int no, start, cnt;
        scanf("%d", &no);
        while (no--) {
            scanf("%d", &start);
            cnt = DFS(start);

            printf("%d", n - cnt);
            for (int i = 1; i <= n; ++i) if(!visit[i])
                printf(" %d", i);
            printf("\n");
            memset(visit, false, sizeof(visit));
        }
        for (int i = 1; i <= n; ++i)
            G[i].clear();
    }
    return 0;
}

/*
Author : bumpy (-_-)
date : 24-Jul-2016
*/
