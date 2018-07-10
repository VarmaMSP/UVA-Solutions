#include <bits/stdc++.h>

using namespace std;

vector< vector< int > > sol;
vector< int > row;

void place(int c) {
    if (c == 8) {
      sol.push_back(row);
      return ;
    }
    for (int r = 0; r < 8; ++r) {
        bool canPlace = true;
        for (int i = 0; i < c && canPlace; ++i) {
            if (row[i] == r) canPlace = false;
            if (abs(row[i] - r) == abs(i - c)) canPlace = false;
        }
        if (canPlace) {
            row[c] = r;
            place(c + 1);
        }
    }
}

int main() {
    for (int c = 0; c < 8; ++c) {
        row.push_back(c);
    }
    place(0);
    int tt, g[8][8], n = sol.size();
    scanf("%d", &tt);
    while (tt--) {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                scanf("%d", g[i] + j);
            }
        }
        int max = INT_MIN;
        for (int i = 0; i < n; ++i) {
            int score = 0;
            for (int j = 0; j < 8; ++j) {
                score += g[j][sol[i][j]];
            }
            if (score > max) max = score;
        }
        printf("%5d\n", max);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 10-July-2018
*/
