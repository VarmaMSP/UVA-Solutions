#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt, p, tmp, deg[1010];
    string line;
    stringstream sin;
    cin >> tt;
    while (tt--) {
        int min = INT_MAX;
        cin >> p;
        cin.ignore();
        for (int u = 1; u <= p; ++u) {
            deg[u] = 0;
            getline(cin, line);
            sin << line;
            while (sin >> tmp) deg[u] += 1;
            if (deg[u] < min) min = deg[u];
            sin.clear();
        }
        bool first = true;
        for (int u = 1; u <= p; ++u) {
            if (deg[u] == min) {
                if (!first) cout << " ";
                cout << u;
                first = false;
            }
        }
        cout << endl;
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 3-July-2018
*/
