#include <bits/stdc++.h>

using namespace std;

vector<int> G[100100], GT[100100], S;
bool visit[100100];
int compID[100100];

void DFS1(int u) {
    visit[u] = true;
    for (auto v: G[u]) {
        if (!visit[v]) {
            DFS1(v);
        }
    }
    S.push_back(u);
}

void DFS2(int u, int ID) {
    visit[u] = true;
    compID[u] = ID;
    for (auto v: GT[u]) {
        if(!visit[v]) {
            DFS2(v, ID);
        }
    }
}

int main() {
    int tt, n, m;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d %d", &n, &m);
        while (m--) {
            int u, v;
            scanf("%d %d", &u, &v); --u, --v;
            G[u].push_back(v);
            GT[v].push_back(u);
        }
        for (int u = 0; u < n; ++u) {
            if(!visit[u]) {
                DFS1(u);
            }
        }
        memset(visit, false, sizeof(visit));
        int ID = 0;
        for (int i = n-1; i >= 0; --i) {
            if(!visit[S[i]]) {
                DFS2(S[i], ID++);
            }
        }
        memset(visit, false, sizeof(visit));
        vector <bool> hasParent(ID, false);
        int res = 0;
        for (int u = 0; u < n; ++u) {
            for (auto v: G[u]){
                if (compID[u] != compID[v] && !hasParent[compID[v]]) {
                    hasParent[compID[v]] = true;
                    ++res;
                }
            }
        }
        printf("%d\n", ID - res);
        for (int u = 0; u < n; ++u) {
            G[u].clear();
            GT[u].clear();
        }
        S.clear();
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 26-Jul-2016
*/


