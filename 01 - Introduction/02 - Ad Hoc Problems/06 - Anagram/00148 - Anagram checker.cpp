#include <bits/stdc++.h>

using namespace std;

int cnt[26];
string str, word;
set< string > pharse;
vector< string > S, res;

void solve(int p) {
    bool valid = true, sol = true;
    for (int i = 0; i < 26; ++i) {
        if (cnt[i] < 0) valid = sol = false;
        if (cnt[i] > 0) sol = false;
    }
    if (valid && !sol) {
        for (int i = p; i < S.size(); ++i) if (pharse.find(S[i]) == pharse.end()){
            for (auto c: S[i]) cnt[c - 'A'] -= 1; res.push_back(S[i]);
            solve(i + 1);
            for (auto c: S[i]) cnt[c - 'A'] += 1; res.pop_back();
        }
    }
    if (valid && sol) {
        cout << str << " =";
        for (auto s: res) {
            cout << " " << s;
        }
        cout << endl;
    }
}

int main() {
    while (cin >> str && str != "#") {
        S.push_back(str);
    }
    cin.ignore();
    while (getline(cin, str) && str != "#") {
        for (auto c: str) if (c != ' ') cnt[c - 'A'] += 1;
        stringstream ss(str);
        while (ss >> word) {
            pharse.insert(word);
        }
        solve(0);
        pharse.clear();
        memset(cnt, 0, sizeof(cnt));
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 19-Aug-2018
*/
