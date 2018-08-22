#include <bits/stdc++.h>

using namespace std;

int cnt, indeg[26];
char res[26];
bool node[26];
vector<int> G[26];

void topo(int id) {
    if (id < cnt) {
        for (int u = 0; u < 26; ++u) if (node[u] && indeg[u] == 0) {
            for (auto v: G[u]) indeg[v] -= 1;
            node[u] = false, res[id] = 'a' + u;
            topo(id + 1);
            for (auto v: G[u]) indeg[v] += 1;
            node[u] = true;
        }
        return ;
    }
    res[id] = '\0';
    puts(res);
}

int main() {
    char u, v;
    bool firstLine = true;
    string str;
    while (getline(cin, str)) {
        istringstream nodes(str);
        cnt = 0;
        while (nodes >> u) {
            node[u - 'a'] = true;
            cnt++;
        }
        getline(cin, str);
        stringstream edges(str);
        while (edges >> u >> v) {
            G[u - 'a'].push_back(v - 'a');
            indeg[v - 'a'] += 1;
        }
        if (!firstLine) printf("\n"); firstLine = false;
        topo(0);
        for(int i = 0; i < 26; ++i) {
            G[i].clear();
        }
        memset(node, false, sizeof(node));
        memset(indeg, 0, sizeof(indeg));
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 26-Jul-2016
*/
