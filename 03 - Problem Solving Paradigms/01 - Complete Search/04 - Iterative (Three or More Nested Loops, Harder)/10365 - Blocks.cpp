#include <bits/stdc++.h>

int main() {
    int tt, n;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d", &n);
        int min = INT_MAX;
        for (int l = 1; l <= n; ++l) {
            for (int h = 1; l * h <= n; ++h) {
                if (n % (l * h) == 0) {
                    int w = n / (l * h);
                    int a = 2 * (l * h + h * w + w * l);
                    if (a < min) min = a;
                }
            }
        }
        printf("%d\n", min);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 9-July-2018
*/
