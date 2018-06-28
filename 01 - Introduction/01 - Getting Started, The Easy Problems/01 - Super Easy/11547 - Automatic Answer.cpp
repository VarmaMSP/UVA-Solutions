#include <bits/stdc++.h>

typedef long long int i64;

int main() {
    int tt, n;
    scanf("%d", &tt);
    while (tt--) {
       scanf("%d", &n);
       i64 res = n * 567;
       res /= 9;
       res += 7492;
       res *= 235;
       res /= 47;
       res -= 498;
       if (res < 0) res *= -1;
       res %= 100;
       res /= 10;
       printf("%lld\n", res);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 28-Jun-2018
*/
