#include <bits/stdc++.h>

using namespace std;

vector<int> G[27], S;
bool isnode[27], visit[27];

void DFS(int u) {
    visit[u] = true;
    for (auto v: G[u]) {
        if (isnode[v] && !visit[v]) {
            DFS(v);
        }
    }
    S.push_back(u);
}

int main() {
    string a, b;
    cin >> a;
    while (cin >> b && b[0] != '#') {
        int l = min(a.size(), b.size());
        for (int i = 0; i < l; ++i) {
            if (a[i] != b[i]) {
                G[b[i] - 'A'].push_back(a[i] - 'A');
                isnode[a[i] - 'A'] = true;
                isnode[b[i] - 'A'] = true;
                break;
            }
        }
        a.assign(b.begin(), b.end());
    }
    for (int i = 0; i < 26; ++i) {
        if (isnode[i] && !visit[i]) {
            DFS(i);
        }
    }
    for (auto it: S) {
        printf("%c", (char)(it + 'A'));
    }
    printf("\n");
    return 0;
}

/*
Author: bumpy (-_-)
date: 31-Jul-2016
*/
