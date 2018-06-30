#include <bits/stdc++.h>

int main() {
    int tt, n, duration, i = 1;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d", &n);
        int mile = 0, juice = 0;
        while (n--) {
            scanf("%d", &duration);
            mile += (duration / 30) + 1;
            juice += (duration / 60) + 1;
        }
        mile *= 10;
        juice *= 15;
        if (mile < juice) printf ("Case %d: Mile %d\n", i++, mile);
        if (mile > juice) printf ("Case %d: Juice %d\n", i++, juice);
        if (mile == juice) printf ("Case %d: Mile Juice %d\n", i++, mile);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 30-Jun-2018
*/
