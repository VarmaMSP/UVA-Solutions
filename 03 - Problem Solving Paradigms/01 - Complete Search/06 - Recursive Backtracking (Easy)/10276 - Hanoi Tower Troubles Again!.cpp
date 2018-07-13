#include <bits/stdc++.h>

int n, peg[51], max;

void place(int b) {
    if (b > max) max = b - 1;
    for (int i = 0; i < n; ++i) {
        if (peg[i] == 0) {
            peg[i] = b;
            place(b + 1);
            break;
        }
        int tmp = sqrt(peg[i] + b);
        if (tmp * tmp == (peg[i] + b)) {
            peg[i] = b;
            place(b + 1);
            break;
        }
    }
}

int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d", &n);
        max = -1;
        place(1);
        printf("%d\n", max);
        memset(peg, 0, sizeof(peg));
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 13-July-2018
*/
