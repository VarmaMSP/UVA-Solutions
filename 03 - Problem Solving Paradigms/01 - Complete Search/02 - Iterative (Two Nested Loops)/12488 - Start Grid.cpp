#include <bits/stdc++.h>

int main() {
    int n, start[25], endPos[25], x;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) scanf("%d", start + i);
        for (int i = 0; i < n; ++i) scanf("%d", &x), endPos[x] = i;
        int overtakes = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (endPos[start[i]] > endPos[start[j]]) {
                    overtakes += 1;
                }
            }
        }
        printf("%d\n", overtakes);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 4-July-2018
*/
