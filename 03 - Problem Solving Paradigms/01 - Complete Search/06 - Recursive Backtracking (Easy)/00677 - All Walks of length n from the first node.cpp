#include <bits/stdc++.h>

using namespace std;

int n, l, G[11][11];
bool visit[11], found;
vector< int > path;

void solve(int u) {
    if (path.size() < l) {
        for (int v = 0; v < n; ++v) if (G[u][v] && !visit[v]) {
            path.push_back(v), visit[v] = true;
            solve(v);
            path.pop_back(), visit[v] = false;
        }
        return ;
    }
    found = true;
    printf("(1");
    for (int i = 0; i < path.size(); ++i) {
        printf(",%d", path[i] + 1);
    }
    printf(")\n");
}

int main() {
    int tmp = 0;
    do {
        scanf("%d %d", &n, &l);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", G[i] + j);
            }
        }
        if (tmp == -9999) puts("");
        visit[0] = true;
        found = false;
        solve(0);
        if (!found) {
            printf("no walk of length %d\n", l);
        }
    } while (scanf("%d", &tmp) != EOF);
    return 0;
}

/*
Author: bumpy (-_-)
date: 24-July-2018
*/
