#include <bits/stdc++.h>

using namespace std;

int n, des, o, maxT, total = 0, cap[25];
tuple< int, int, int > order[25];

void solve(int i) {
    if (i < o) {
        int src = get<0>(order[i]);
        int des = get<1>(order[i]);
        int cnt = get<2>(order[i]);
        if (cnt <= cap[src]) {
            total += (des - src) * cnt;
            for (int j = src; j < des; ++j) {
                cap[j] -= cnt;
            }
            solve(i + 1);
            total -= (des - src) * cnt;
            for (int j = src; j < des; ++j) {
                cap[j] += cnt;
            }
        }
        solve(i + 1);
        return ;
    }
    maxT = max(maxT, total);
}

int main() {
    while (scanf("%d %d %d", &n, &des, &o) && (n|des|o)) {
        for (int i = 0; i < o; ++i) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            order[i] = {x, y, z};
        }
        maxT = -1;
        sort(order, order + o);
        for (int i = 0; i < des; ++i) {
            cap[i] = n;
        }
        solve(0);
        printf("%d\n", maxT);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 13-July-2018
*/
