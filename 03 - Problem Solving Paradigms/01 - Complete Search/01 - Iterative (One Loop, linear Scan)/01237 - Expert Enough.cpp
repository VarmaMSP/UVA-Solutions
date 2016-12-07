#include <bits/stdc++.h>

using namespace std;

vector < pair <string, pair<int, int> > > D;

int main() {
    int tt, d, l, h, q, p;
    string m;
    cin >> tt;
    while (tt--) {
        cin >> d;
        for (int i = 0; i < d; ++i) {
            cin >> m >> l >> h;
            D.push_back({m, {l, h}});
        }
        cin >> q;
        while (q--) {
            cin >> p;
            int id, cnt = 0;
            for (int i = 0; i < d; ++i) {
                if (D[i].second.first <= p && p <= D[i].second.second) {
                    ++cnt;
                    id = i;
                }
            }
            if (cnt == 1)
                cout << D[id].first << endl;
            else
                cout << "UNDETERMINED" << endl;
        }
        if (tt)
            cout << endl;
        D.clear();
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 10-Jul-2016
*/

