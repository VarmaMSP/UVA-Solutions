#include <bits/stdc++.h>

using namespace std;

int m, n;
char arena[110][110];

char changeDir(char dir, char turn) {
    switch (dir) {
        case 'N':
            return (turn == 'D' ? 'L' : 'O');
        case 'S':
            return (turn == 'D' ? 'O' : 'L');
        case 'L':
            return (turn == 'D' ? 'S' : 'N');
        case 'O':
            return (turn == 'D' ? 'N' : 'S');
    }
}

int main() {
    int s, x, y;
    char dir, instr;
    while (scanf("%d %d %d", &m, &n, &s) && m|n|s) {
        bool posFound = false;
        gets(arena[0]);
        for (int i = 0; i < m; ++i) {
            gets(arena[i]);
            for (int j = 0; j < n ; ++j) {
                char tmp = arena[i][j];
                if (tmp != '.' && tmp != '*' && tmp != '#') {
                    posFound = true;
                    dir = tmp;
                    x = i;
                    y = j;
                }
            }
        }
        int tickets = 0;
        for (int i = 0; i < s; ++i) {
            scanf("%c", &instr);
            if (instr == 'D' || instr == 'E') {
                dir = changeDir(dir, instr);
                continue;
            }
            if (instr == 'F') {
                if (dir == 'N' && x > 0 && arena[x - 1][y] != '#')
                    --x;
                else if (dir == 'O' && y > 0&& arena[x][y - 1] != '#')
                    --y;
                else if (dir == 'S' && x < m - 1 && arena[x + 1][y] != '#')
                    ++x;
                else if (dir == 'L' && y < n - 1 && arena[x][y + 1] != '#')
                    ++y;

                if (arena[x][y] == '*') {
                    tickets += 1;
                    arena[x][y] = '.';
                }
            }
        }
        printf("%d\n", tickets);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 11-Dec-2016
*/
