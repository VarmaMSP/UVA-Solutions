#include <bits/stdc++.h>

using namespace std;

int street[50010];
int avenue[50010];

int main() {
    int tt, S, A, F;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d %d %d", &S, &A, &F);

        for (int i = 0; i < F; ++i) {
            scanf("%d %d", street + i, avenue + i);
        }

        sort(street, street + F);
        sort(avenue, avenue + F);

        int x, y;
        if (F & 1) {
            x = street[F / 2];
            y = avenue[F / 2];
        } else {
            x = street[F/2 - 1];
            y = avenue[F/2 - 1];
        }
        printf("(Street: %d, Avenue: %d)\n", x, y);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 02-Jan-17
*/
