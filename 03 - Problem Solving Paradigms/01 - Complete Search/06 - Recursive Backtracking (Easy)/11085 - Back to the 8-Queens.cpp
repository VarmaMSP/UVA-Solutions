#include <bits/stdc++.h>

using namespace std;

int row[8];
vector< vector< int > > sol;

void solve(int c) {
    if (c < 8) {
        for (int r = 0; r < 8; ++r) {
            bool canPlace = true;
            for (int i = 0; i < c && canPlace; ++i) {
                if (row[i] == r) canPlace = false;
                if (abs(row[i] - r) == abs(i - c)) canPlace = false;
            }
            if (canPlace) {
                row[c] = r;
                solve(c + 1);
            }
        }
        return ;
    }
    sol.push_back(vector<int> (row, row + 8));
}

int main() {
    solve(0);
    int c = 1;
    while (scanf("%d %d %d %d %d %d %d %d", row, row + 1, row + 2, row + 3, row + 4, row + 5, row + 6, row + 7) != EOF) {
        int minMoves = INT_MAX;
        for (int i = 0; i < sol.size(); ++i) {
            int moves = 0;
            for (int c = 0; c < 8; ++c) {
                moves += row[c] - 1 != sol[i][c] ? 1 : 0;
            }
            minMoves = min(moves, minMoves);
        }
        printf("Case %d: %d\n", c++, minMoves);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 24-July-2018
*/
