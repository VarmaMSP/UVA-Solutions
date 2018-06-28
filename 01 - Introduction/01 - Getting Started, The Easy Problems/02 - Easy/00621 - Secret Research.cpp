#include<bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    string str;
    scanf("%d", &tt);
    while (tt--) {
        cin >> str;
        int l = str.size();
        if (str == "1" || str == "4" || str == "78") {
            puts("+");
            continue;
        }
        if (str[l - 2] == '3' && str[l - 1] == '5') {
            puts("-");
            continue;
        }
        if (str[0] == '9' && str[l - 1] == '4') {
            puts("*");
            continue;
        }
        if (str[0] == '1' && str[1] == '9' && str[2] == '0') {
            puts("?");
            continue;
        }
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 28-Jun-2018
*/
