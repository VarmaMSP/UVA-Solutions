#include <bits/stdc++.h>

using namespace std;

int day[2525], cnt[2525];
bool visit[2525];
vector< int > G[2525];

void bfs(int s) {
    queue< int > Q;
    day[s] = 0;
    cnt[0] += 1;
    visit[s] = true;
    Q.push(s);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (auto v: G[u]) if (!visit[v]) {
            day[v] = day[u] + 1;
            visit[v] = true;
            cnt[day[v]] += 1;
            Q.push(v);
        }
    }
}

int main() {
    int e, n, tmp;
    scanf("%d", &e);
    for (int i = 0; i < e; ++i) {
        scanf("%d", &n);
        for (int j = 0; j < n; ++j) {
            scanf("%d", &tmp);
            G[i].push_back(tmp);
        }
    }
    int tt, s;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d", &s);
        bfs(s);
        int firstBoom, maxBoom = INT_MIN;
        for (int i = 1; i < e && cnt[i] > 0; ++i) {
            if (cnt[i] > maxBoom) {
                maxBoom = cnt[i];
                firstBoom = i;
            }
        }
        if (maxBoom > INT_MIN) {
            printf("%d %d\n", maxBoom, firstBoom);
        } else {
            printf("%d\n", cnt[1]);
        }
        memset(day, 0, sizeof(day));
        memset(cnt, 0, sizeof(cnt));
        memset(visit, false, sizeof(visit));
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 22-Jul-2018
*/
