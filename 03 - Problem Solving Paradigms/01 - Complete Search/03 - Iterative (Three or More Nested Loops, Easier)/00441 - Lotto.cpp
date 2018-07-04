#include <bits/stdc++.h>

using namespace std;

int main() {
    int k, s[14];
    bool first = true;
    while (scanf("%d", &k) && k) {
        for (int i = 0; i < k; ++i) {
          scanf("%d", s + i);
        }
        if (!first) puts("");
        first = false;
        sort(s, s + k);
        for (int a = 0; a < k; ++a) {
            for (int b = a + 1; b < k; ++b) {
                for (int c = b + 1; c < k; ++c) {
                    for (int d = c + 1; d < k; ++d) {
                        for (int e = d + 1; e < k; ++e) {
                            for (int f = e + 1; f < k; ++f) {
                                printf("%d %d %d %d %d %d\n", s[a], s[b], s[c], s[d], s[e], s[f]);
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 4-July-2018
*/
