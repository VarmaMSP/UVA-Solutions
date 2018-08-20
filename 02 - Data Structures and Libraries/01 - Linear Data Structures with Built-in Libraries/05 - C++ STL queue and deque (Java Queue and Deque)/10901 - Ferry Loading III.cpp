#include <bits/stdc++.h>

using namespace std;

int main() {
    char bankPos[10];
    int tt, t, n, m, time;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d %d %d", &n, &t, &m);
        queue< pair< int, int > > bank[2];
        for (int i = 0; i < m; ++i) {
            scanf("%d %s", &time, bankPos);
            if (bankPos[0] == 'l')
                bank[0].push({i, time});
            else
                bank[1].push({i, time});
        }
        int pos = 0, T = 0;
        vector< int > res(m);
        while (!(bank[0].empty() && bank[1].empty())) {
            int firstCar = INT_MAX;
            if (!bank[pos].empty()) {
                firstCar = bank[pos].front().second;
            }
            if (!bank[pos ^ 1].empty()) {
                //check if a car arrived earlier, the other side
                firstCar = min(firstCar, bank[pos ^ 1].front().second);
            }
            //check if first car arrives after time T
            T = max(T, firstCar);
            int cnt = 0;
            while (!bank[pos].empty() && bank[pos].front().second <= T && cnt < n) {
                res[bank[pos].front().first] = T + t;
                bank[pos].pop();
                ++cnt;
            }
            T += t;
            pos ^= 1;
        }
        for (auto x: res) {
            printf("%d\n", x);
        }
        if (tt) printf("\n");
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 03-Jan-2017
*/
