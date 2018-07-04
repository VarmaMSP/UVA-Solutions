#include <bits/stdc++.h>

int main() {
    int tt, n, a[1010], b[1010];
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
        }
        memset(b, 0, sizeof(b));
        int sum = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (a[j] <= a[i]) b[i] += 1;
            }
            sum += b[i];
        }
        printf("%d\n", sum);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 4-July-2018
*/
