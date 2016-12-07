#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt, n, snr, jnr;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d %d", &n, &snr); --n;
        int diff = INT_MIN;
        while (n--) {
            scanf("%d", &jnr);
            diff = max(diff, snr - jnr);
            snr  = max(snr, jnr);
        }
        printf("%d\n", diff);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 10-Jul-2016
*/
