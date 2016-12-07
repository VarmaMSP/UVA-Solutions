#include <bits/stdc++.h>

using namespace std;

vector<int> G[110];
int learn[110], total, endStage;
bool visit[110];

void DFS(int u) {
    int id = -1, maxLearn = INT_MIN;
    visit[u] = true;
    total += learn[u];
    for (auto v: G[u]) {
        if(!visit[v]) {
            if(learn[v] > maxLearn){
                maxLearn = learn[v];
                id = v;
            }
        }
    }

    if(id == -1)
        endStage = u;
    else
        DFS(id);
}

int main() {
    int tt, u, v, m, n, k = 1;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%d", learn + i);
        }
        while (m--) {
            scanf("%d %d", &u, &v);
            G[u].push_back(v);
        }
        total = 0;
        DFS(0);
        printf("Case %d: %d %d\n", k++, total, endStage);
        for(int i = 0; i < n; ++i)
            G[i].clear();
        memset(visit, false, sizeof(visit));
    }
    return 0;
}

/*
Author : bumpy (-_-)
date : 26-Jul-2016
*/
