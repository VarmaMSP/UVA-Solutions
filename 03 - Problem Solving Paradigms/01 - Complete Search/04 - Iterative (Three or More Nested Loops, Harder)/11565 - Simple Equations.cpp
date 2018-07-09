#include <bits/stdc++.h>

int main() {
    int tt, a, b, c;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d %d %d", &a, &b, &c);
        bool found = false;
        for (int x = -100; x <= 100 && !found; ++x) {
            for (int y = x + 1; y <= 100 && !found; ++y) {
                for (int z = y + 1; z <= 100 && !found; ++z) {
                    if (x + y + z == a && x * y * z == b && x*x + y*y + z*z == c) {
                        printf("%d %d %d\n", x, y, z);
                        found = true;
                    }
                }
            }
        }
        if (!found) puts("No solution.");
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 9-July-2018
*/
