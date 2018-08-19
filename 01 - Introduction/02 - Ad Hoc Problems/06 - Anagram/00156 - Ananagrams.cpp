#include <bits/stdc++.h>

using namespace std;

map< string, vector< string > > S;
vector< string > res;

int main() {
    string line, word, tmp;
    while (getline(cin, line), line != "#") {
        stringstream ss(line);
        while (ss >> word) {
            string tmp;
            for (auto c: word) {
                tmp.push_back(tolower(c));
            }
            sort(tmp.begin(), tmp.end());
            S[tmp].push_back(word);
        }
    }
    for (auto x: S) {
        if (x.second.size() == 1) {
            res.push_back(x.second[0]);
        }
    }
    sort(res.begin(), res.end());
    for (auto x: res) {
        cout << x << endl;
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 19-Aug-2018
*/
