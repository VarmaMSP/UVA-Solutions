#include <bits/stdc++.h>

using namespace std;

int n, cnt, placed[26];
string even = "aeiou";
string odd = "bcdfghjklmnpqrstvwxyz";
double total, prob[26] = {
  12.53, 1.42, 4.68, 5.86, 13.68, 0.69, 1.01, 0.70, 6.25, 0.44, 0.00, 4.97, 3.15,
  6.71 , 8.68, 2.51, 0.88,  6.87, 7.98, 4.63, 3.93, 0.90, 0.02, 0.22, 0.90, 0.52
};

void solve(int p, double b) {
    if (p <= n && p % 2 == 0) {
        for (auto e: even) if (placed[e] < 2) {
            placed[e - 'a'] += 1;
            solve(p + 1, b + p * prob[e - 'a']);
            placed[e - 'a'] -= 1;
        }
        return ;
    }
    if (p <= n && p % 2 != 0) {
        for (auto o: odd) if (placed[o] < 2) {
            placed[o - 'a'] += 1;
            solve(p + 1, b + p * prob[o - 'a']);
            placed[o - 'a'] -= 1;
        }
        return ;
    }
    cnt += 1;
    total += b;
}

int main() {
    int tt;
    string str;
    cin >> tt;
    while (tt--) {
        cin >> str;
        n = str.size();
        double beauty = 0.0;
        for (int i = 0; i < n; ++i) {
            beauty += (i + 1) * prob[str[i] - 'a'];
        }
        cnt = 0, total = 0.0;
        placed[str[0] - 'a'] += 1;
        solve(2, prob[str[0] - 'a']);
        placed[str[0] - 'a'] -= 1;
        double avg = total / cnt;
        if (beauty < avg)  puts("below");
        if (beauty >= avg) puts("above or equal");
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 26-July-2018
*/
