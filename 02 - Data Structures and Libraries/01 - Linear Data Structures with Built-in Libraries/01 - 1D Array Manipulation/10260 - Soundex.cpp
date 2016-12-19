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
        x = -1;
        for (int i = 0; i < strlen(str); ++i) {
            y = id[str[i]];
            if (y != 0 && y != x) {
                printf("%d", y);
            }
            x = y;
        }
        printf("\n");
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 19-Dec-2016
*/
