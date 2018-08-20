#include <bits/stdc++.h>

using namespace std;

vector< string > arr;
map< string, vector< string > > S;

int main() {
    string str;
    while (cin >> str, str != "XXXXXX") {
        arr.push_back(str);
    }
    sort(arr.begin(), arr.end());
    for (auto s: arr) {
        string tmp = s;
        sort(tmp.begin(), tmp.end());
        S[tmp].push_back(s);
    }
    while (cin >> str, str != "XXXXXX") {
        sort(str.begin(), str.end());
        if (S[str].size() > 0) {
            for (auto s: S[str]) cout << s << endl;
        } else {
            cout << "NOT A VALID WORD" << endl;
        }
        cout << "******" << endl;
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 20-Aug-2018
*/
