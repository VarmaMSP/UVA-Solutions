#include <bits/stdc++.h>

using namespace std;

vector< string > name;
map< string, int > receives, gives;

int main() {
    int n, amt, m;
    bool firstLine = true;
    string line, a, b;
    while (cin >> n) {
        cin.ignore();
        getline(cin, line);
        stringstream ss(line);
        while (ss >> a) {
            name.push_back(a);
        }
        while (n--) {
            cin >> a >> amt >> m;
            if (m > 0) {
                for (int i = 0; i < m; ++i) {
                    cin >> b;
                    receives[b] += amt / m;
                }
                gives[a] += amt;
                receives[a] += amt - (amt / m) * m;
            }
        }
        if (!firstLine) cout << endl; firstLine = false;
        for (auto n: name) {
            cout << n << " " << receives[n] - gives[n] << endl;
        }
        name.clear(); receives.clear(); gives.clear();
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 17-Aug-2018
*/
