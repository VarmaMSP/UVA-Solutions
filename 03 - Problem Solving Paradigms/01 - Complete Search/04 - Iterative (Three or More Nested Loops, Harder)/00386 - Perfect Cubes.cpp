#include <bits/stdc++.h>

int main() {
    for (int a = 6; a <= 200; ++a) {
        for (int b = 2; 3*b*b*b <= a*a*a; ++b) {
            for (int c = b; b*b*b + 2*c*c*c <= a*a*a; ++c) {
                for (int d = c; b*b*b + c*c*c + d*d*d <= a*a*a; ++d) {
                    if (b*b*b + c*c*c + d*d*d == a*a*a) {
                        printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
                    }
                }
            }
        }
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 9-July-2018
*/
