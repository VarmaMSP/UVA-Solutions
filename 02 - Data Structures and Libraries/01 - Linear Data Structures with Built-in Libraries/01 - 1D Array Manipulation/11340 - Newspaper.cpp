#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt, k, m;
    char c;
    double p;
    cin >> tt;
    while (tt--) {
        map< char, double > price;
        cin >> k;
        while (k--) {
            cin >> c >> p;
            price[c] = p;
        }
        cin >> m;
        cin.ignore();
        string line;
        double total = 0;
        while (m--) {
            getline(cin, line);
            for (int i = 0; i < line.size(); ++i) {
                total += price[line[i]];
            }
        }
        cout << fixed << setprecision(2) << (total / 100) << "$\n";
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 2-July-2018
*/
