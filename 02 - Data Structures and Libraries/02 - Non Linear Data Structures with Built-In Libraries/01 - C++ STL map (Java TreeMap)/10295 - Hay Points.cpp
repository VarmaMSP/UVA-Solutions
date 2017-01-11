#include <bits/stdc++.h>

using namespace std;

map< string, int > dict;

int main() {
    string tmp, word;
    int m, n, hayPoint;
    cin >> m >> n;
    while (m--) {
        cin >> word >> hayPoint;
        dict[word] = hayPoint;
    }

    while (n--) {
        long long int salary = 0;

        while (getline(cin, tmp) && tmp != ".") {
            stringstream ss(tmp);
            while (ss >> word) {
                salary += dict[word];
            }
        }
        cout << salary << endl;
    }
    return 0;
}

/*
Author: bumpy(-_-)
date: 12-Jan-2017
*/
