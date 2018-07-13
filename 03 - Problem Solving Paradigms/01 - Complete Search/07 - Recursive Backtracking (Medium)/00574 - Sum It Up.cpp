#include <bits/stdc++.h>

using namespace std;

int t, n, a[15], c;
vector< int > res;
set< vector< int > > rset;

void solve(int i, int rem) {
    if (i < n) {
        if (a[i] <= rem) {
            res.push_back(a[i]);
            solve(i + 1, rem - a[i]);
            res.pop_back();
        }
        solve(i + 1, rem);
        return ;
    }
    if (rem == 0) rset.insert(res);
}

int main() {
    while (scanf("%d %d", &t, &n) && (t|n)) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
        }
        c = 0;
        printf("Sums of %d:\n", t);
        solve(0, t);
        if (rset.size() > 0) {
            for (auto it = rset.rbegin(); it != rset.rend(); ++it) {
                auto vec = *it;
                printf("%d", vec[0]);
                for (int i = 1; i < vec.size(); ++i)
                    printf("+%d", vec[i]);
                puts("");
            }
        } else {
            puts("NONE");
        }
        rset.clear();
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 13-July-2018
*/
