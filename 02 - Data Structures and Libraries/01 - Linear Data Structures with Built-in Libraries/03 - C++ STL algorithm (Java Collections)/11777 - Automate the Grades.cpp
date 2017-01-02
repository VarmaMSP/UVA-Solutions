#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt, t1, t2, f, a, c1, c2, c3, k = 1;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d %d %d %d %d %d %d", &t1, &t2, &f, &a, &c1, &c2, &c3);
        int c = (c1 + c2 + c3 - min(c1, min(c2, c3))) / 2;
        int result = t1 + t2 + f + a + c;

        printf("Case %d: ", k++);
        if (result >= 90) 
            printf("A\n");
        else if (result >= 80) 
            printf("B\n");
        else if (result >= 70)
            printf("C\n");
        else if (result >= 60)
            printf("D\n");
        else
            printf("F\n");
    }
    return 0;
}

/*
Author: bumpy(-_-)
date: 2-Jan-2017
*/

