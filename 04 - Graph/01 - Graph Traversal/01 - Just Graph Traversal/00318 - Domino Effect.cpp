#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

vector<pii> G[510];
int n, Time[510];

void Dijkstra(int s) {
    for (int u = 1; u <= n; ++u) {
        Time[u] = INT_MAX;
    }
    priority_queue< pii, vector<pii>, greater<pii> > Q;
    Time[s] = 0;
    Q.push({0, s});
    while (!Q.empty()) {
        int u = Q.top().second;
        Q.pop();
        for (auto &x: G[u]) {
            int v = x.second;
            int t = x.first;
            if (Time[v] > Time[u] + t) {
                Time[v] = Time[u] + t;
                Q.push({Time[v], v});
            }
        }
    }
}

int main() {
    int m, u, v, l, k = 1;
    while (scanf("%d %d", &n, &m) && n|m) {
        while (m--) {
            scanf("%d %d %d", &u, &v, &l);
            G[u].push_back({l, v});
            G[v].push_back({l, u});
        }
        Dijkstra(1);
        int x = distance(Time, max_element(Time + 1, Time + 1 + n));
        int y = 0;
        double T = Time[x];
        for (int u = 1; u <= n; ++u) {
            for (auto &w: G[u]) {
                int v = w.second;
                int t = w.first;
                double timeToFall = (Time[u] + Time[v] + t) / 2.0;
                if (T < timeToFall) {
                    x = min(u, v);
                    y = max(u, v);
                    T = timeToFall;
                }
            }
        }
        printf("System #%d\n", k++);
        if (y == 0) {
            printf("The last domino falls after %.1f seconds, at key domino %d.\n\n", T, x);
        } else {
            printf("The last domino falls after %.1f seconds, between key dominoes %d and %d.\n\n", T, x, y);
        }
        for(int i = 1; i <= n; ++i) {
            G[i].clear();
        }
        memset(Time, 0, sizeof(Time));
    }
    return 0;
}

/*
Author : bumpy (-_-)
date : 24-Jul-2016
*/
