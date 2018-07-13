#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt, n, g[9][9];
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", g[i] + j);
            }
        }
        int y[] = {0, 1, 2, 3, 4, 5, 6, 7};
        int alice = INT_MAX;
        do {
            int score = 0;
            for (int x = 0; x < n; ++x) {
                score += g[x][y[x]];
            }
            alice = min(alice, score); // Bob always trys to minimise alice's score.
        } while (next_permutation(y, y + n));
        printf("%d\n", alice);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 13-July-2018
*/
