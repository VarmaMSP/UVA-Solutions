#include <bits/stdc++.h>

using namespace std;

int G[50005];
bool visit[50005], inStack[50005];

int DFS(int u) {
    visit[u] = true;
    int cnt = 0;
    int v = G[u];
    inStack[u] = true;
    if (!inStack[v]) {
        cnt += DFS(v);
    }
    inStack[u] = false;
    return 1 + cnt;
}

int main() {
    int tt, n, u, v, k = 1;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &u, &v);
            G[u] = v;
        }
        int person = -1;
        int maxPeople = -1;
        for (int u = 1; u <= n; ++u) {
            if (!visit[u]) {
                int tmp = DFS(u);
                if (tmp > maxPeople) {
                    maxPeople = tmp;
                    person = u;
                }
            }
        }
        printf("Case %d: %d\n", k++, person);
        memset(visit, false, sizeof(visit));
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 11-Dec-2016
*/
