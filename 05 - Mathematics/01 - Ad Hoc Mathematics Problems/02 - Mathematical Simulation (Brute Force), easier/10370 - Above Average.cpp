#include <bits/stdc++.h>

int main() {
    int tt, n, cnt;
    double s, a[1010];
    scanf("%d", &tt);
    while (tt--) {
        s = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%lf", a + i);
            s += a[i];
        }
        s /= (double)n;
        cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > s) cnt += 1;
        }
        printf("%.3lf", 100.0 * ((double)cnt)/((double)n));
        puts("%");
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 9-Aug-2018
*/
