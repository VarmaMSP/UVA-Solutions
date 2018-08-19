#include <bits/stdc++.h>

using namespace std;

bool ispalin(char *p, char *q) {
    while (p < q) {
        if (*p != *q) return false;
        p += 1;
        q -= 1;
    }
    return true;
}

int main() {
    char str[88];
    while (scanf("%s", str) != EOF) {
        set< string > s;
        int l = strlen(str);
        for (int i = 0; i < l; ++i) {
            for (int j = i; j < l; ++j) {
                if (ispalin(str + i, str + j)) {
                    s.insert(string(str + i, j - i + 1));
                }
            }
        }
        printf("The string '%s' contains %lu palindromes.\n", str, s.size());
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 19-Aug-2018
*/
