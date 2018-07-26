#include <bits/stdc++.h>

int n, max, G[110][110];
bool colored[110], sol[110];

void solve(int u, int blacks) {
    if (u < n) {
        bool canColor = true;
        for (int v = 0; v < n; ++v) if (G[u][v] && colored[v]) {
            canColor = false;
            break;
        }
        if (canColor) {
            colored[u] = true;
            solve(u + 1, blacks + 1);
            colored[u] = false;
        }
        solve(u + 1, blacks);
        return ;
    }
    if (blacks > max) {
        max = blacks;
        memcpy(sol, colored, sizeof(sol));
    }
}

int main() {
    int tt, u, v, k;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d %d", &n, &k);
        while (k--) {
            scanf("%d %d", &u, &v), --u, --v;
            G[u][v] = G[v][u] = 1;
        }
        max = INT_MIN;
        solve(0, 0);
        printf("%d\n", max);
        for (int i = 0; i < n; ++i) if (sol[i]) {
            printf("%d", i + 1);
            for (int j = i + 1; j < n; ++j) if (sol[j]) {
                printf(" %d", j + 1);
            }
            printf("\n");
            break;
        }
        memset(G, 0, sizeof(G));
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 26-July-2018
*/
