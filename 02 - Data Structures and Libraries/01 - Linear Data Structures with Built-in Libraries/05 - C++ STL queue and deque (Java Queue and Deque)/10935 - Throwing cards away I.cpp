#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    queue< int > Q;
    while (scanf("%d", &n) && n) {
        for (int i = 1; i <= n; ++i) {
            Q.push(i);
        }

        printf("Discarded cards:");
        while (Q.size() > 1) {
            printf(" %d", Q.front()), Q.pop();

            int x = Q.front(); Q.pop();
            Q.push(x);
            if (Q.size() > 1) {
                printf(",");
            }
        }
        printf("\n");
        printf("Remaining card: %d\n", Q.front()), Q.pop();
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 03-Jan-2017
*/
