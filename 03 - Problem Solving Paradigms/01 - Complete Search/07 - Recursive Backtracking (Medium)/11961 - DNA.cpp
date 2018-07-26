#include <bits/stdc++.h>

using namespace std;

int n, k;
string dna;
set< string > mutation;

void solve(int p) {
    if (p < n) {
        if (k > 0) {
            char tmp = dna[p];
            k -= 1;
            dna[p] = 'A', solve(p + 1);
            dna[p] = 'G', solve(p + 1);
            dna[p] = 'C', solve(p + 1);
            dna[p] = 'T', solve(p + 1);
            k += 1;
            dna[p] = tmp;
        }
        solve(p + 1);
        return ;
    }
    if (k == 0) mutation.insert(dna);
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        cin >> n >> k;
        cin >> dna;
        solve(0);
        cout << mutation.size() << endl;
        for (auto m: mutation) {
            cout << m << endl;
        }
        mutation.clear();
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 26-July-2018
*/
