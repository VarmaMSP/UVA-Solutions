#include <bits/stdc++.h>

int main() {
    int tt, a, b, c, i = 1;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d %d %d", &a, &b, &c);
        printf("Case %d: ", i++);
        if (a <= 20 && b <= 20 && c <= 20)
            puts("good");
        else
            puts("bad");
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 28-Jun-2018
*/
