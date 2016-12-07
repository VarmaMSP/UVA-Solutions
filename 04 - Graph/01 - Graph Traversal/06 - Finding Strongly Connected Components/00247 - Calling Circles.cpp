#include <bits/stdc++.h>

using namespace std;

map<int, string> name;
map<string, int> id;
vector<int> G[30], GT[30], comp[30], S;
bool visit[30];

int DFS1(int u) {
    visit[u] = true;
    for (auto v: G[u]) {
        if (!visit[v]) {
            DFS1(v);
        }
    }
    S.push_back(u);
}

int DFS2(int u, int compId) {
    visit[u] = true;
    comp[compId].push_back(u);
    for (auto v: GT[u]) {
        if (!visit[v]) {
            DFS2(v, compId);
        }
    }
}

int main() {
    int n, m, kk = 1;
    string p, q;
    while (cin >> n >> m && n|m) {
        int k = 0;
        while (m--) {
            cin >> p >> q;
            if (id.find(p) == id.end()) {
                id[p] = k++;
                name[id[p]] = p;
            }
            if (id.find(q) == id.end()) {
                id[q] = k++;
                name[id[q]] = q;
            }
            G[id[p]].push_back(id[q]);
            GT[id[q]].push_back(id[p]);
        }
        for (int i = 0; i < k; ++i) {
            if (!visit[i]) {
                DFS1(i);
            }
        }
        memset(visit, false, sizeof(visit));

        int ID = 0;
        for (int i = k - 1; i >= 0; --i) {
            if(!visit[S[i]]) {
                DFS2(S[i], ID++);
            }
        }
        memset(visit, false, sizeof(visit));
        if(kk > 1)
            cout << endl;
        cout << "Calling circles for data set " << kk++ << ":\n";
        for (int i = 0; i < ID; ++i) {
            bool first = true;
            for (auto x: comp[i]){
                if (first) {
                    cout << name[x];
                    first = false;
                } else {
                    cout << ", " << name[x];
                }
            }
            cout << endl;
        }
        for (int i = 0; i < 30; ++i) {
            G[i].clear();
            GT[i].clear();
            comp[i].clear();
        }
        name.clear();
        id.clear();
        S.clear();
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 28-Jul-2016
*/
