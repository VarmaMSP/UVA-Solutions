#include <bits/stdc++.h>

using namespace std;

map< string, string > dict;
map< string, string >::const_iterator pos;

int main() {
    string tmp, english, foreign;

    while (getline(cin, tmp) && tmp != "") {
        stringstream ss(tmp);
        ss >> english >> foreign;
        dict[foreign] = english;
    }
    while (cin >> foreign) {
        pos = dict.find(foreign);

        if (pos == dict.end())
            cout << "eh" << endl;
        else
            cout << pos->second << endl;
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 12-Jan-2017
*/
