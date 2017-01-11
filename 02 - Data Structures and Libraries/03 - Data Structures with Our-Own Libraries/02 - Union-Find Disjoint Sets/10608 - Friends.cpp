#include <bits/stdc++.h>

using namespace std;

int p[30300], cnt[30300];

int find_set(int x) {
    if (p[x] != x) 
        p[x] = find_set(p[x]);
    return p[x];
}

int main() {
    int tt, u, v, x, y, n, m; 
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            p[i] = i;
            cnt[i] = 1;
        }
        while (m--) {
            scanf("%d %d", &u, &v);
            x = find_set(u);
            y = find_set(v);
            if (x != y) {
                p[y] = x;
                cnt[x] += cnt[y];
            }
        }
        int res = INT_MIN;
        for (int i = 1; i <= n; ++i) if (p[i] == i) {
            if (res <  cnt[i]) { 
                res = cnt[i];
            }
        }
        printf("%d\n", res);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 04-Jan-2017
*/


