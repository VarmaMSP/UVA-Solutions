#include <bits/stdc++.h>

int main() {
    int tt, M, N, X, Y;
    while (scanf("%d", &tt) && tt) {
        scanf("%d %d", &M, &N);
        while (tt--) {
            scanf("%d %d", &X, &Y);
            if (X == M || Y == N) {
                puts("divisa");
                continue;
            }
            printf("%c%c\n", (Y > N ? 'N' : 'S'), (X > M ? 'E' : 'O'));
        }
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 28-Jun-2018
*/
