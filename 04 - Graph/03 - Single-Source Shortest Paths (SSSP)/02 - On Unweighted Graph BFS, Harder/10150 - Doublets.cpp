#include <bits/stdc++.h>

using namespace std;

map< string, bool > visit;
map< string, string > p;
set< string > dict;

bool bfs(string s, string des) {
    queue< string > Q;
    Q.push(s);
    while (!Q.empty()) {
        string u = Q.front(); Q.pop();
        string v = u;
        for (int i = 0; i < v.size(); ++i) {
            for (int j = 0; j < 26; ++j) if (('a' + j) != u[i]) {
                v[i] = 'a' + j;
                if (dict.find(v) != dict.end() && !visit[v]) {
                    visit[v] = true;
                    p[v] = u;
                    Q.push(v);
                    if (v == des) return true;
                }
            }
            v[i] = u[i];
        }
    }
    return false;
}

void printPath(string src, string u) {
    if (p[u] != src) printPath(src, p[u]);
    cout << u << endl;
}

int main() {
    bool firstLine = true;
    string str, u, v;
    while (getline(cin, str) && !str.empty()) {
        dict.insert(str);
    }
    while (cin >> u >> v) {
        if (!firstLine) puts(""); firstLine = false;
        if (dict.find(u) == dict.end() || dict.find(v) == dict.end()) {
            puts("No solution.");
            continue;
        }
        if (bfs(u, v)) {
            cout << u << endl;
            printPath(u, v);
        } else {
            puts("No solution.");
        }
        p.clear();
        visit.clear();
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 29-July-2018
*/

/* useful test case
input:
abc
acc
acd

aba bcd
zba acc
zba bcd
aba abc
aba aba

output:
No solution.

No solution.

No solution.

aba
abc

aba
abc
aba
*/
