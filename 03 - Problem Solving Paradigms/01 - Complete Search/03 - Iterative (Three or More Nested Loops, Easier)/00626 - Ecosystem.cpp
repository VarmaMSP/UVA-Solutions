#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, g[110][110];
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", g[i] + j);
            }
        }
        int cycles = 0;
        for (int a = 0; a < n; ++a) {
            for (int b = 0; b < n; ++b) if (b != a){
                for (int c = 0; c < n; ++c) if (c != b && c != a) {
                    if (g[a][b] && g[b][c] && g[c][a]) {
                        if ((a < b && b < c) || (a > b && b > c)) {
                            printf("%d %d %d\n", a + 1, b + 1, c + 1);
                            cycles += 1;
                        }
                    }
                }
            }
        }
        printf("total:%d\n\n", cycles);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 4-July-2018
*/
