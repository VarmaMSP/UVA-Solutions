#include <bits/stdc++.h>

using namespace std;

int main() {
    int l;
    string turn;
    while (cin >> l && l) {
        int dir = 0;
        for (int i = 0; i < l - 1; ++i) {
            cin >> turn;
            if (turn == "No") {
                continue;
            }
            if (turn == "+y") {
                if (dir == 0)      dir = 2;
                else if (dir == 1) dir = 3;
                else if (dir == 2) dir = 1;
                else if (dir == 3) dir = 0;
            }
            if (turn == "-y") {
                if (dir == 0)      dir = 3;
                else if (dir == 1) dir = 2;
                else if (dir == 2) dir = 0;
                else if (dir == 3) dir = 1;
            }
            if (turn == "+z") {
                if (dir == 0)      dir = 4;
                else if (dir == 1) dir = 5;
                else if (dir == 4) dir = 1;
                else if (dir == 5) dir = 0;
            }
            if (turn == "-z") {
                if (dir == 0)      dir = 5;
                else if (dir == 1) dir = 4;
                else if (dir == 4) dir = 0;
                else if (dir == 5) dir = 1;
            }
        }
        if (dir == 0) puts("+x");
        if (dir == 1) puts("-x");
        if (dir == 2) puts("+y");
        if (dir == 3) puts("-y");
        if (dir == 4) puts("+z");
        if (dir == 5) puts("-z");
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 17-Aug-2018
*/
