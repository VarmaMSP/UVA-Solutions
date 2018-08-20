#include <bits/stdc++.h>

using namespace std;

int main() {
    char bankPos[10];
    int tt, l, length, m;
    scanf("%d", &tt);
    while(tt--) {
        scanf("%d %d ", &l, &m);
        l *= 100;
        queue< int > bank[2];
        while (m--) {
            scanf("%d %s", &length, bankPos);
            if (bankPos[0] == 'l')
                bank[0].push(length);
            else
                bank[1].push(length);
        }
        int cnt = 0, pos = 0;
        while (!(bank[0].empty() && bank[1].empty())) {
            int len = 0;
            while (!bank[pos].empty() && len + bank[pos].front() <= l) {
                len += bank[pos].front();
                bank[pos].pop();
            }
            cnt += 1;
            pos ^= 1;
        }
        printf("%d\n", cnt);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 11-Jan-2017
*/
