#include <bits/stdc++.h>

using namespace std;

/*
B - 0, C - 1, G - 2;
input - B, C, G - box[0], box[1], box[2]
*/

char color[3] = {'B', 'C', 'G'};

int main() {
    int x[3], y[3], z[3];
    while (scanf("%d %d %d %d %d %d %d %d %d",
                &x[0], &x[2], &x[1], &y[0], &y[2],
                &y[1], &z[0], &z[2], &z[1]) != EOF){
        int p[3] = {0, 1, 2};
        int minMov = INT_MAX;
        char col[5], temp[5];
        col[3] = 0;
        do {
            int mov = 0;
            mov += y[p[0]] + z[p[0]];
            mov += x[p[1]] + z[p[1]];
            mov += x[p[2]] + y[p[2]];
            if(mov < minMov) {
                col[0] = color[p[0]];
                col[1] = color[p[1]];
                col[2] = color[p[2]];
                minMov = mov;
            }
        } while (next_permutation(p, p + 3));
        printf("%s %d\n", col, minMov);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 10-Jul-2016
*/
