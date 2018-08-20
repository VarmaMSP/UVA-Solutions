#include <bits/stdc++.h>

using namespace std;

vector< string > arr, arrS;

int main() {
    int tt;
    string line;
    cin >> tt;
    cin.ignore(); cin.ignore();
    while(tt--) {
        while (getline(cin, line) && !line.empty()) {
            arr.push_back(line);
        }
        sort(arr.begin(), arr.end());
        for (auto s: arr) {
            string str = s;
            str.erase(remove(str.begin(), str.end(), ' '), str.end());
            sort(str.begin(), str.end());
            arrS.push_back(str);
        }
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = i + 1; j < arr.size(); ++j) {
                if (arrS[i] == arrS[j]) {
                    cout << arr[i] << " = " << arr[j] << endl;
                }
            }
        }
        if (tt) cout << endl;
        arr.clear(), arrS.clear();
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 20-Aug-2018
*/
