#include <bits/stdc++.h>

int main() {
    int tt, n, c = 1;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d", &n);
        printf("Case #%d: %d", c++, n);
        int cnt = 0;
        for (int m = 2; m * m < n && cnt < 2; ++m) {
            if (n % m == 0) {
                printf(" = %d * %d", m, n / m);
                cnt += 1;
            }
        }
        printf("\n");
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 9-Aug-2018
*/
