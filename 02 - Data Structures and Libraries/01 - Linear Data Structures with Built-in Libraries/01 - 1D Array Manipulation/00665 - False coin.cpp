#include <bits/stdc++.h>

int main() {
    char res[3];
    int tt, n, k, p, tmp;
    bool w[101], isfalse[101];
    scanf("%d", &tt);
    while (tt--) {
        memset(isfalse, true, sizeof(isfalse));
        scanf("%d %d", &n, &k);
        while (k--) {
            memset(w, false, sizeof(w));
            scanf("%d", &p);
            for (int i = 0; i < 2 * p; ++i) {
                scanf("%d", &tmp); w[tmp] = true;
            }
            scanf("%s", res);
            for (int i = 1; i <= n; ++i) {
                if (res[0] == '=' && w[i])  isfalse[i] = false;
                if (res[0] == '<' && !w[i]) isfalse[i] = false;
                if (res[0] == '>' && !w[i]) isfalse[i] = false;
            }
        }
        int coin, count = 0;
        for (int i = 1; i <= n; ++i) {
            if (isfalse[i]) coin = i, count += 1;
        }
        printf("%d\n", count == 1 ? coin : 0);
        if (tt) puts("");
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 2-July-2018
*/
