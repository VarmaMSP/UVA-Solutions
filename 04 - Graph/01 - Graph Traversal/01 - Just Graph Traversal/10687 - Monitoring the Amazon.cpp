#include <bits/stdc++.h>

using namespace std;

int n;
bool visit[1010];
pair< int, int > s[1010];

inline int square(int x) { return x * x; }

void dfs(int p, int q) {
    int a = -1, b = -1;
    int x = INT_MAX, y = INT_MAX;
    for (int i = 0; i < n; ++i) {
        int d = square(p - s[i].first) + square(q - s[i].second);
        if (d < x) {
            y = x, b = a;
            x = d, a = i;
        } else if (d < y) {
            y = d, b = i;
        }
    }
    if (!visit[a]) {
        visit[a] = true;
        dfs(s[a].first, s[a].second);
    }
    if (!visit[b]) {
        visit[b] = true;
        dfs(s[b].first, s[b].second);
    }
}

int main() {
    int p, q;
    while (scanf("%d", &n) && n) {
        scanf("%d %d", &p, &q);
        n -= 1;
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &s[i].first, &s[i].second);
        }
        sort(s, s + n), dfs(p, q);
        bool canReach = true;
        for (int i = 0; i < n && canReach; ++i) {
            if (!visit[i]) canReach = false;
        }
        if (canReach)  puts("All stations are reachable.");
        if (!canReach) puts("There are stations that are unreachable.");
        memset(visit, false, sizeof(visit));
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 20-Jul-2018
*/
