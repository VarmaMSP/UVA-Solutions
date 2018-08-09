#include <bits/stdc++.h>

int main() {
    int tt, a, b, c = 1;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d %d", &a, &b);
        int s = 0;
        for (int i = a; i <= b; ++i) {
            if (i & 1) s += i;
        }
        printf("Case %d: %d\n", c++, s);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 9-Aug-2018
*
