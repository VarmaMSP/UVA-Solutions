#include <bits/stdc++.h>

using namespace std;

int main() {
    int y, p, e[100100];
    while (scanf("%d", &y) != EOF) {
        scanf("%d", &p);
        for (int i = 0; i < p; ++i) {
            scanf("%d", e + i);
        }
        int max = INT_MIN, a, b;
        for (int i = 0; i < p; ++i) {
            if (e[i] + y - 1 <= e[p - 1]) {
                int d = distance(e, upper_bound(e, e + p, e[i] + y - 1));
                if (d < p && d - i > max) {
                    a = e[i];
                    b = e[d - 1];
                    max = d - i;
                }
            }
        }
        printf("%d %d %d\n", max, a, b);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 16-July-2018
*/
