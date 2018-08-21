#include <bits/stdc++.h>

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int a = (n & 0x000000ff) << 24u;
        int b = (n & 0x0000ff00) << 8u;
        int c = (n & 0x00ff0000) >> 8u;
        int d = (n & 0xff000000) >> 24u;
        printf("%d converts to %d\n", n, a | b | c | d);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 21-Aug-2018
*/
