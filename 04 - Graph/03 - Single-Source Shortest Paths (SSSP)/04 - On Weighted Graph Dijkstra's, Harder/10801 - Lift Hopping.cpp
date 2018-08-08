#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int > pii;

int d[110], g[110][110];

int dijkstra(int s, int des) {
    priority_queue< pii, vector< pii >, greater< pii > > Q;
    for (int i = 0; i < 110; ++i) {
        d[i] = INT_MAX;
    }
    d[s] = 0;
    Q.push({d[s], s});
    while (!Q.empty()) {
        int u = Q.top().second; Q.pop();
        for (int v = 0; v < 100; ++v) if (g[u][v] < INT_MAX) {
            if (d[v] > d[u] + g[u][v] + 60) {
                d[v] = d[u] + g[u][v] + 60;
                Q.push({d[v], v});
            }
        }
    }
    return d[des];
}

int main() {
    int n, k, u, v, w, tmp, t[10];
    string str;
    while (cin >> n >> k) {
        for (int i = 0; i < 110; ++i) {
            for (int j = 0; j < 110; ++j) {
                g[i][j] = INT_MAX;
            }
        }
        for (int i = 0; i < n; ++i) {
            cin >> t[i];
        }
        cin.ignore();
        for (int i = 0; i < n; ++i) {
            getline(cin, str);
            stringstream ss(str);
            vector< int > floor;
            while (ss >> tmp) {
                floor.push_back(tmp);
            }
            for (int j = 0; j < floor.size(); ++j) {
                for (int k = j + 1; k < floor.size(); ++k) {
                    u = floor[j];
                    v = floor[k];
                    w = min((v - u) * t[i], g[u][v]);
                    g[u][v] = g[v][u] = w;
                }
            }
        }
        if (k != 0) {
            int res = dijkstra(0, k);
            if (res == INT_MAX) cout << "IMPOSSIBLE" << endl;
            if (res != INT_MAX) cout << res - 60 << endl;
        } else {
            cout << '0' << endl;
        }
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 8-Aug-2018
*/
