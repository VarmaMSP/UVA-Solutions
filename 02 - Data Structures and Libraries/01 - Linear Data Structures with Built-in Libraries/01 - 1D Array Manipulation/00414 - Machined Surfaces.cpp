#include <bits/stdc++.h>

using namespace std;

int space[30];
string g[15];

int main() {
    int n;
    while (scanf("%d", &n) && n) {
        cin.ignore();
        for (int i = 0; i < n; ++i) {
            getline(cin, g[i]);
        }
        int minSpace = INT_MAX;
        for (int i = 0; i < n; ++i) {
            space[i] = 0;
            for (int j = 0; j < 25; ++j) {
                if (g[i][j] == ' ') space[i] += 1;
            }
            minSpace = min(minSpace, space[i]);
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res += space[i] - minSpace;
        }
        printf("%d\n", res);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 20-Aug-2018
*/
