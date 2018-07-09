#include <bits/stdc++.h>
#define MAX 50001

int sol[MAX][3];

void preprocess() {
    for (int i = 0; i < MAX; ++i) {
        sol[i][0] = -1;
    }
    for (int i = 0; i < 224; ++i) {
        for (int j = i; j < 224; ++j) {
            for (int k = j; k < 224; ++k) {
                int n = i*i + j*j + k*k;
                if (n < MAX && sol[n][0] == -1) {
                    sol[n][0] = i;
                    sol[n][1] = j;
                    sol[n][2] = k;
                }
            }
        }
    }
}

int main() {
    preprocess();
    int tt, k;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d", &k);
        if (sol[k][0] == -1) {
            puts("-1");
        } else {
            printf("%d %d %d\n", sol[k][0], sol[k][1], sol[k][2]);
        }
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 9-July-2018
*/
