#include <bits/stdc++.h>

using namespace std;

int n, indeg[26];
bool node[26], found;
vector< int > G[26], S;

void topo() {
    if (S.size() < n) {
        for (int u = 0; u < 26; ++u) if (node[u]) {
            if (indeg[u] == 0) {
                for (auto v: G[u]) indeg[v] -= 1;
                node[u] = false; S.push_back(u);
                topo();
                for (auto v: G[u]) indeg[v] += 1;
                node[u] = true; S.pop_back();
            }
        }
        return ;
    }
    cout << (char)('A' + S[0]);
    for (int i = 1; i < n; ++i) {
        cout << " " << (char)('A' + S[i]);
    }
    cout << endl;
    found = true;
}

int main() {
    int tt, u, v;
    string line, str;
    stringstream sin;
    cin >> tt;
    cin.ignore();
    while (tt--) {
        cin.ignore();
        getline(cin, line), sin << line;
        n = 0;
        while (sin >> str) {
            node[str[0] - 'A'] = true;
            n += 1;
        }
        sin.clear();
        getline(cin, line), sin << line;
        while (sin >> str) {
            u = str[0] - 'A';
            v = str[2] - 'A';
            G[u].push_back(v);
            indeg[v] += 1;
        }
        sin.clear();
        found = false; topo();
        if (!found) cout << "NO" << endl;
        if (tt) cout << endl;
        for (int i = 0; i < 26; ++i) {
            G[i].clear();
        }
        memset(node, false, sizeof(node));
        memset(indeg, 0, sizeof(indeg));
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 17-Jul-2018
*/
