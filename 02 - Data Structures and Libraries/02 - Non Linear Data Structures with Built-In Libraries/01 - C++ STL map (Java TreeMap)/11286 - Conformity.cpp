#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, s[5];
    char str[50];
    while (scanf("%d", &n) && n) {
        map< string, int > count;
        while (n--) {
            scanf("%d %d %d %d %d", s, s + 1, s + 2, s + 3, s + 4);
            sort(s, s + 5);
            sprintf(str, "%d%d%d%d%d", s[0], s[1], s[2], s[3], s[4]);
            count[str] += 1;
        }
        int max = INT_MIN;
        for (auto const& x: count) {
            if (x.second > max) max = x.second;
        }
        int res = 0;
        for (auto const& x: count) {
            if (x.second == max) res += x.second;
        }
        printf("%d\n", res);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 2-July-2018
*/
