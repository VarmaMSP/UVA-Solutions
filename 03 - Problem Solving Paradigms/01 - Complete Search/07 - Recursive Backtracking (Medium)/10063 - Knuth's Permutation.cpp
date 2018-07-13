#include <bits/stdc++.h>

using namespace std;

string str, perm;

void gen(int p) {
    if (p < str.size()) {
        for (int i = 0; i <= perm.size(); ++i) {
            perm.insert(i, 1, str[p]);
            gen(p + 1);
            perm.erase(i, 1);
        }
        return ;
    }
    cout << perm << endl;
}

int main() {
    bool first = true;
    while (cin >> str) {
        if (!first) puts("");
        first = false;
        gen(0);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 13-July-2018
*/
