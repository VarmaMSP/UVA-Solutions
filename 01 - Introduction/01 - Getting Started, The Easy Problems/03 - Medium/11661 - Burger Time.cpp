#include <bits/stdc++.h>

using namespace std;

int l, d[2000010];
char s[2000010];

int main() {
    while (scanf("%d", &l) && l) {
        scanf("%s", s);
        int x = -l;;
        for (int i = 0; i < l; ++i) {
            if (s[i] == 'D' || s[i] == 'Z') x = i;
            if (s[i] == 'R' || s[i] == 'Z') d[i] = i - x;
        }
        int y = 2 * l, res = INT_MAX;
        for (int i = l - 1; i >= 0; --i) {
            if (s[i] == 'D' || s[i] == 'Z') y = i;
            if (s[i] == 'R' || s[i] == 'Z') res = min(res, min(d[i], y - i));
        }
        printf("%d\n", res);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 19-Aug-2018
*/
