#include <bits/stdc++.h>

using namespace std;

int trans[220];
bool visit[220];
vector< string > dict;

bool canTrans(string x, string y) {
    int n = 0;
    if (x.size() != y.size()) return false;
    for (int i = 0; i < x.size(); ++i) {
        if (x[i] != y[i]) n += 1;
    }
    return n == 1;
}

int bfs(int s, int d) {
    queue< int > Q;
    visit[s] = false;
    trans[s] = 0;
    Q.push(s);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        if (u == d) return trans[u];
        for (int v = 0; v < dict.size(); ++v) if (!visit[v] && canTrans(dict[u], dict[v])) {
            visit[v] = true;
            trans[v] = trans[u] + 1;
            Q.push(v);
        }
    }
    return 0;
}

int main() {
    int tt, s, d;
    string str, u, v;
    cin >> tt;
    while (tt--) {
        while (cin >> str, str[0] != '*') {
            dict.push_back(str);
        }
        cin.ignore();
        while (getline(cin, str) && !str.empty()) {
            stringstream ss(str);
            ss >> u >> v;
            for (int i = 0; i < dict.size(); ++i) {
                if (dict[i] == u) s = i;
                if (dict[i] == v) d = i;
            }
            cout << u << " " << v << " " << bfs(s, d) << endl;
            memset(visit, false, sizeof(visit));
        }
        if (tt) cout << endl;
        dict.clear();
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 27-July-2018
*/
