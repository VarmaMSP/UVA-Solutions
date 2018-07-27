#include <bits/stdc++.h>

using namespace std;

map< string, vector< string > > G;
map< string, string > p;

void bfs(string s, string d) {
    queue< string > Q;
    p[s] = s;
    Q.push(s);
    while (!Q.empty()) {
        string u = Q.front(); Q.pop();
        for (auto v: G[u]) if (v != p[u]) {
            p[v] = u;
            Q.push(v);
        }
        if (u == d) return;
    }
}

void printPath(string u) {
    if (p[u] != u) printPath(p[u]);
    cout << u[0];
}

int main() {
    int tt, m, n;
    string u, v;
    cin >> tt;
    while (tt--) {
        cin >> m >> n;
        int id = 0;
        while (m--) {
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        while (n--) {
            cin >> u >> v;
            bfs(u, v);
            printPath(v);
            cout << endl;
        }
        if (tt) cout << endl;
        G.clear();
        p.clear();
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 27-July-2018
*/
