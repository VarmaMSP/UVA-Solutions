#include <bits/stdc++.h>

using namespace std;

int main() {
    int k = 1;
    char item[1010];
    while (gets(item) && item[0] != 'e') {
        int l = strlen(item), n = 0;
        stack< char > S[26];
        for (int i = 0; i < l; ++i) {
            bool stackFound = false;
            for (int j = 0; j < n && !stackFound; ++j) {
                if (S[j].top() >= item[i]) {
                    S[j].push(item[i]);
                    stackFound = true;
                }
            }
            if (!stackFound) {
                n += 1;
                S[n - 1].push(item[i]);
            }
        }
        printf("Case %d: %d\n", k++, n);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 11-Jan-2017
*/
