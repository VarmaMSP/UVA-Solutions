#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, cond[21][3];
    while (scanf("%d %d", &n, &m) && (n|m)) {
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d", &cond[i][0], &cond[i][1], &cond[i][2]);
        }
        int cntr = 0, p[8] = {0, 1, 2, 3, 4, 5, 6, 7};

        do {
            bool canSeat = true;
            for (int i = 0; i < m; ++i) {
                int x = distance(p, find(p, p + n, cond[i][0]));
                int y = distance(p, find(p, p + n, cond[i][1]));
                int z = cond[i][2];
                if (z > 0) {
                    if (abs(x - y) >  z) {
                        canSeat = false;
                        break;
                    }
                }
                else if (abs(x - y) < -z) {
                    canSeat = false;
                    break;
                }
            }
            if (canSeat) ++cntr;
        } while(next_permutation(p, p + n));

        printf("%d\n", cntr);
    }
    return 0;
}

/*
Author : bumpy (-_-)
date : 10-Jul-2016
*/
