#include <bits/stdc++.h>

int count, R, C, row[8];

void place(int c) {
    if (c == 8) {
        printf("%2d     ", count++);
        for (int i = 0; i < 8; ++i)
            printf(" %d", row[i] + 1);
        puts("");
        return ;
    }
    if (c == C) {
        place(c + 1);
        return ;
    }
    for (int r = 0; r < 8; ++r) {
        bool canPlace = true;
        if (R == r || abs(R - r) == abs(C - c)) canPlace = false;
        for (int i = 0; i < c && canPlace; ++i) {
            if (row[i] == r || abs(row[i] - r) == abs(i - c)) {
                canPlace = false;
            }
        }
        if (canPlace) {
            row[c] = r;
            place(c + 1);
        }
    }
}

int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d %d", &R, &C);
        count = 1;
        R -= 1; C -= 1;
        row[C] = R;
        puts("SOLN       COLUMN");
        puts(" #      1 2 3 4 5 6 7 8");
        puts("");
        place(0);
        if (tt) puts("");
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 13-July-2018
*/
