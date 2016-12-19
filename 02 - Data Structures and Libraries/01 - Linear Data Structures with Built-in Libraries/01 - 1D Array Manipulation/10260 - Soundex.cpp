#include <bits/stdc++.h>

using namespace std;

map< char, int > id;

void init() {
    id['B'] = id['F'] = id['P'] = id['V'] = 1;
    id['C'] = id['G'] = id['J'] = id['K'] = 2;
    id['Q'] = id['S'] = id['X'] = id['Z'] = 2;
    id['D'] = id['T'] = 3;
    id['L'] = 4;
    id['M'] = id['N'] = 5;
    id['R'] = 6;
}

int main() {
    init();
    char str[100];
    int x, y;
    while (gets(str)) {
        y = -1;
        for (int i = 0; i < strlen(str); ++i) {
            x = id[str[i]];
            if (x != 0 && x != y) {
                printf("%d", x);
            }
            y = x;
        }
        printf("\n");
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 19-Dec-2016
*/
