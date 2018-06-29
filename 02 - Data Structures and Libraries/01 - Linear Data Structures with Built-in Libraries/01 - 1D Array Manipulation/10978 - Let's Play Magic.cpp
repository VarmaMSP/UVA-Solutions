#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    bool placed[52];
    string pos[52], card, name;
    while (cin >> n && n) {
        int p = -1;
        memset(placed, 0, sizeof(placed));
        for (int i = 0; i < n; ++i) {
            cin >> card >> name;
            int l = name.size();
            while (l--) {
                do {
                    p = (p + 1) % n;
                } while (placed[p]);
            }
            pos[p] = card;
            placed[p] = true;
        }
        for (int i = 0; i < n; ++i) {
            if (i) cout << " ";
            cout << pos[i];
        }
        cout << endl;
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 29-Jun-2018
*/
