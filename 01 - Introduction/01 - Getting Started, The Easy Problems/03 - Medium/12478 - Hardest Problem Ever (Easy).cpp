#include <bits/stdc++.h>

using namespace std;

string name[8]  = { "RAKIBUL", "ANINDYA", "MOSHIUR", "SHIPLU", "KABIR", "SUNNY", "OBAIDA", "WASI" };
string nameS[8] = { "RAKIBUL", "ANINDYA", "MOSHIUR", "SHIPLU", "KABIR", "SUNNY", "OBAIDA", "WASI" };
string grid[9] = {
    "OBIDAIBKR",
    "RKAULHISP",
    "SADIYANNO",
    "HEISAWHIA",
    "IRAKIBULS",
    "MFBINTRNO",
    "UTOYZIFAH",
    "LEBSYNUNE",
    "EMOTIONAL"
};

int main() {
    for (int i = 0; i < 8; ++i) {
        sort(nameS[i].begin(), nameS[i].end());
    }
    for (int x = 0; x < 8; ++x) {
        int cnt = 0;
        int l = nameS[x].size();
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                string v, h;
                if (j + l <= 9) for (int k = j; k < j + l; ++k) h.push_back(grid[i][k]);
                if (i + l <= 9) for (int k = i; k < i + l; ++k) v.push_back(grid[k][j]);
                sort(h.begin(), h.end());
                sort(v.begin(), v.end());
                cnt += h == nameS[x];
                cnt += v == nameS[x];
            }
        }
        if (cnt > 1) {
            cout << name[x] << endl;
            break;
        }
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 19-Aug-2018
*/
