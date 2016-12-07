#include <bits/stdc++.h>

using namespace std;

int G[110][110], n;
bool canReach[110], visit[110], res[110][110];

void DFS (int u, int skip) {
    if(u == skip)
        return;
    visit[u] = true;
    for (int v = 0; v < n; ++v) {
        if (G[u][v] && !visit[v]) {
            DFS(v, skip);
        }
    }
}

void printDashes() {
    printf("+");
    for(int i = 1; i < 2*n; ++i) {
        printf("-");
    }
    printf("+\n");
}

int main() {
    int tt, k = 1;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d", &n);
        for(int u = 0; u < n; ++u) {
            for(int v = 0; v < n; ++v) {
                scanf("%d", &G[u][v]);
            }
        }
        DFS(0, -1);
        for (int u = 0; u < n; ++u) {
            canReach[u] = visit[u];
        }
        for (int u = 0; u < n; ++u) {
            for (int v = 0; v < n; ++v) {
                res[u][v] = false;
            }
        }
        for (int v = 0; v < n; ++v) {
            if (canReach[v]) {
                memset(visit, false, sizeof(visit));
                DFS(0, v);
                for (int u = 0; u < n; ++u) {
                    if (canReach[u] && !visit[u]) //v dominates u
                        res[v][u] = true;
                }
            }
        }
        printf("Case %d:\n", k++);
        for (int i = 0; i < n; ++i) {
            printDashes();
            for (int j = 0; j < n; ++j) {
                printf(res[i][j] ? "|Y" : "|N");
            }
            printf("|\n");
        }
        printDashes();
        memset(res, false, sizeof(res));
        memset(visit, false, sizeof(visit));
    }
    return 0;
}

/*
Author : bumpy (-_-)
date : 30-Jul-2016
*/
