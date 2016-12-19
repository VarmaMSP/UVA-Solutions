#include <bits/stdc++.h>

using namespace std;

map< string, int > id;
map< int, string > beverage;
vector< int > G[110];
int indeg[110];

int main() {
    int m, n, k = 1;
    bool isFirstLine = true;
    string b1, b2;
    while (cin >> n) {
        for (int i = 0; i < n; ++i) {
            cin >> b1;
            beverage[i] = b1;
            id[b1] = i;
        }
        scanf("%d", &m);
        while (m--) {
            cin >> b1 >> b2;
            G[id[b1]].push_back(id[b2]);
            ++indeg[id[b2]];
        }

        cout << "Case #" << k++ << ": Dilbert should drink beverages in this order:";
        //khans Algorithm
        priority_queue< int, vector< int >, greater< int > > Q;
        for (int u = 0; u < n; ++u) {
            if (indeg[u] == 0) {
                Q.push(u);
            }
        }
        while (!Q.empty()) {
            int u = Q.top();
            cout << " " << beverage[u];
            Q.pop();
            for (auto v: G[u]) {
                if ((--indeg[v]) == 0) {
                    Q.push(v);
                }
            }
        }
        cout << ".\n\n";

        beverage.clear();
        id.clear();
        for (int i = 0; i < n; ++i)
            G[i].clear();
        memset(indeg, 0, sizeof(indeg));
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 15-Dec-2016
*/
