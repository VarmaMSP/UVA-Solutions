#include <bits/stdc++.h>

using namespace std;

typedef long long int i64;

int main() {
    int n, k, tmp;
    multiset< int > urn;
    while (scanf("%d", &n) && n) {
        i64 cost = 0;
        while (n--) {
            scanf("%d", &k);
            while (k--) {
                scanf("%d", &tmp);
                urn.insert(tmp);
            }
            auto low = urn.begin();
            auto high = prev(urn.end());
            cost += *high - *low;
            urn.erase(low);
            urn.erase(high);
        }
        printf("%lld\n", cost);
        urn.clear();
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 2-July-2018
*/
