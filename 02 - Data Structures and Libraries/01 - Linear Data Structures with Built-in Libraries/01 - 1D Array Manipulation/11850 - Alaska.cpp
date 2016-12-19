#include <bits/stdc++.h>

using namespace std;

int p[1423];

int main() {
    int n, x, y;
    while (scanf("%d", &n) && n) {
        bool isPoss = true;
        for (int i = 0; i < n; ++i) {
            scanf("%d", p + i);
        }
        sort(p, p + n);

        x = p[0];
        for (int i = 1; i < n; ++i) {
            y = p[i];
            if (y - x > 200) {
                isPoss = false;
            }
            x = y;
        }
        if (1422 - y > 100) {
            isPoss = false;
        }

        if (isPoss)
            puts("POSSIBLE");
        else
            puts("IMPOSSIBLE");
    }
    return 0;
}

/*
Author: bumpy (-_-)
date; 19-Dec-2016
*/
