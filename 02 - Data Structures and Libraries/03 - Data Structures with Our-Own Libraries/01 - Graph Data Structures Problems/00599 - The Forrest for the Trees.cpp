#include <bits/stdc++.h>

using namespace std;

int G[26][26], total;
bool visit[26];

void dfs(int u, int prev) {
    total += 1;
    visit[u] = true;
    for (int v = 0; v < 26; ++v) {
        if (G[u][v] && v != u && v != prev) {
            dfs(v, u);
        }
    }
}

int main() {
    int tt;
    string str;
    cin >> tt;
    while (tt--) {
        while (cin >> str && str[0] != '*') {
            G[str[1] - 'A'][str[3] - 'A'] = 1;
            G[str[3] - 'A'][str[1] - 'A'] = 1;
        }
        cin >> str;
        for (int i = 0; i < str.size(); i += 2) {
            G[str[i] - 'A'][str[i] - 'A'] = 1;
        }
        int tree = 0, acorn = 0;
        for (int u = 0; u < 26; ++u) if (!visit[u]) {
            total = 0;
            dfs(u, -1);
            if (total > 1) tree += 1;
            if (total == 1 && G[u][u] == 1) acorn += 1;
        }
        cout << "There are " << tree << " tree(s) and " << acorn << " acorn(s)." << endl;
        memset(G, 0, sizeof(G));
        memset(visit, false, sizeof(visit));
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 3-July-2018
*/
