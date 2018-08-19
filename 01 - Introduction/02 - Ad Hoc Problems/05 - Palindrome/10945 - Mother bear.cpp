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
    char s[1010];
    while (gets(s), strcmp(s, "DONE") != 0) {
        int d = 0, l = strlen(s);
        for (int i = 0; i < l; ++i) {
            if (s[i] == '.' || s[i] == ',' || s[i] == '!' || s[i] == '?' || s[i] == '\'' || s[i] == ' ') {
                d += 1;
            } else {
                if ('A' <= s[i] && s[i] <= 'Z') s[i] = (char)('a' + (s[i] - 'A'));
                s[i - d] = s[i];
            }
        }
        s[l - d] = '\0';
        if (ispalin(s, s + l - d - 1)) {
            puts("You won't be eaten!");
        } else {
            puts("Uh oh..");
        }
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 19-Aug-2018
*/
