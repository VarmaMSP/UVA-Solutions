#include <bits/stdc++.h>

int main() {
    int v, t;
    while (scanf("%d %d", &v, &t) != EOF) {
        printf("%d\n", 2 * v * t);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 8-Aug-2018
*/

/*
  v = u + at
  s = ut + (1/2)(at2)
    = 2ut + 2at2
    = 2t(u + at)
    = 2vt
*/
