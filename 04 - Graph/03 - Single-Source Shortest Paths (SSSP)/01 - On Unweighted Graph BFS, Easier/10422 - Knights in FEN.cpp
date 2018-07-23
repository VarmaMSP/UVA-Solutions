#include <bits/stdc++.h>

using namespace std;

int reqMoves;
int dx[] = {1, -1, 2, 2, 1, -1, -2, -2};
int dy[] = {-2, -2, -1, 1, 2, 2, -1, 1};
string b[5], *B = new string[5] { "11111", "01111", "00 11", "00001", "00000" };

bool compare() {
    for (int i = 0; i < 5; ++i)
        if (b[i] != B[i]) return false;
    return true;
}

void solve(int x, int y, int m) {
    if (m < reqMoves) {
        if (compare()) {
            reqMoves = m;
            return;
        }
        for (int i = 0; i < 8; ++i) {
            int X = dx[i] + x;
            int Y = dy[i] + y;
            if (0 <= X && X < 5 && 0 <= Y && Y < 5) {
                swap(b[X][Y], b[x][y]);
                solve(X, Y, m + 1);
                swap(b[X][Y], b[x][y]);
            }
        }
    }
}

int main() {
    int tt;
    cin >> tt;
    getline(cin, b[0]);
    while (tt--) {
        for (int i = 0; i < 5; ++i) {
            getline(cin, b[i]);
        }
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (b[i][j] == ' ') {
                    reqMoves = 11;
                    solve(i, j, 0);
                    if (reqMoves < 11) {
                        printf("Solvable in %d move(s).\n", reqMoves);
                    } else {
                        puts("Unsolvable in less than 11 move(s).");
                    }
                }
            }
        }
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 23-Jul-2018
*/
