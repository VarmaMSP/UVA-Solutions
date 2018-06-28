#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt, a[3], i = 1;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d %d %d", a, a + 1, a + 2);
        sort(a, a + 3);
        printf("Case %d: %d\n", i++, a[1]);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 28-Jun-2018
*/
