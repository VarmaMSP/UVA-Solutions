#include <bits/stdc++.h>

using namespace std;

map< string, int > nameId;
vector< int > G[1010], GT[1010], S;
bool visit[1010];

void DFS1(int u) {
    visit[u] = true;
    for (auto v: G[u]) if (!visit[v]) {
        DFS1(v);
    }
    S.push_back(u);
}

void DFS2(int u) {
    visit[u] = true;
    for (auto v: GT[u]) if (!visit[v]) {
        DFS2(v);
    }
}

int main() {
    int p, t, u, v;
    string name;
    while (cin >> p >> t && (p|t)) {
        getline(cin, name);
        for (int i = 0; i < p; ++i) {
            getline(cin, name);
            nameId[name] = i;
        }
        while (t--) {
            getline(cin, name); u = nameId[name];
            getline(cin, name); v = nameId[name];
            G[u].push_back(v);
            GT[v].push_back(u);
        }
        for (int u = 0; u < p; ++u) {
            if (!visit[u]) DFS1(u);
        }
        memset(visit, false, sizeof(visit));
        int groups = 0;
        for (int i = S.size() - 1; i >= 0; --i) {
            if (!visit[S[i]]) {
                DFS2(S[i]);
                groups += 1;
            }
        }
        cout << groups << endl;
        for (int i = 0; i < p; ++i) {
            G[i].clear();
            GT[i].clear();
        }
        S.clear();
        nameId.clear();
        memset(visit, false, sizeof(visit));
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 17-Jul-2018
*/
