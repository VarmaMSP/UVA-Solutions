#include <bits/stdc++.h>

using namespace std;

struct player {
    string name;
    int attack, defence;
};

bool compare(player const& l, player const& r) {
    if (l.attack > r.attack) return true;
    if (l.attack < r.attack) return false;
    if (l.defence < r.defence) return true;
    if (l.defence > r.defence) return false;
    return l.name < r.name;
}

int main() {
    int tt, a, d, c = 1;
    string str, sq1[5], sq2[5];
    player p[10];
    cin >> tt;
    while (tt--) {
        for (int i = 0; i < 10; ++i) {
            cin >> str >> a >> d;
            p[i].name = str;
            p[i].attack = a;
            p[i].defence = d;
        }
        sort(p, p + 10, compare);
        for (int i = 0; i < 5; ++i) {
            sq1[i] = p[i].name;
            sq2[i] = p[i + 5].name;
        }
        sort(sq1, sq1 + 5);
        sort(sq2, sq2 + 5);
        cout << "Case " << c++ << ":" << endl;
        cout << "(" << sq1[0];
        for (int i = 1; i < 5; ++i) cout << ", " << sq1[i];
        cout << ")" << endl;
        cout << "(" << sq2[0];
        for (int i = 1; i < 5; ++i) cout << ", " << sq2[i];
        cout << ")" << endl;
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 9-July-2018
*/
