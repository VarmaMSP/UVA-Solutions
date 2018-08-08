#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt, n, a[20], c = 1;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
        }
        sort(a, a + n);
        printf("Case %d: %d\n", c++, a[n / 2]);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 8-Aug-2018
*/
