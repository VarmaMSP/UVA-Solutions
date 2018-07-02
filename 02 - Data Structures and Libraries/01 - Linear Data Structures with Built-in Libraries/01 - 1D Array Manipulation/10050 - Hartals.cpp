#include <bits/stdc++.h>

int main() {
    int tt, n, p, h;
    bool day[3651];
    scanf("%d", &tt);
    while (tt--) {
        memset(day, false, sizeof(day));
        scanf("%d %d", &n, &p);
        while (p--) {
            scanf("%d", &h);
            int d = h;
            while (d <= n) {
                day[d] = true;
                d += h;
            }
        }
        int count = 0;
        for (int i = 1; i <= n; ++i) {
            bool isFri = (i - 6) % 7 == 0;
            bool isSat = (i - 7) % 7 == 0;
            if (day[i] && !isFri && !isSat) count += 1;
        }
        printf("%d\n", count);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 2-July-2018
*/
