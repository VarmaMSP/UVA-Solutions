#include <bits/stdc++.h>

using namespace std;

map<char, int> dirId;
//          N, E, S, W
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
bool scent[100][100], fell;
int m, n;

void init() {
    dirId['N'] = 0;
    dirId['E'] = 1;
    dirId['S'] = 2;
    dirId['W'] = 3;
}

char changeDir(char curr, char turn) {
    switch (curr) {
        case 'N': return (turn == 'R' ? 'E' : 'W');
        case 'E': return (turn == 'R' ? 'S' : 'N');
        case 'S': return (turn == 'R' ? 'W' : 'E');
        case 'W': return (turn == 'R' ? 'N' : 'S');
    }
}

void moveInDir(char dir, int *x, int *y, bool moveBack = false) {
    int z = dirId[dir];
    if (!moveBack) {
        *x += dx[z];
        *y += dy[z];
        if (*x < 0 || *y < 0 || *x > m || *y > n)
            moveInDir(dir, x, y, true);
    } else {
        *x -= dx[z];
        *y -= dy[z];
        if (!scent[*x][*y])
            scent[*x][*y] = fell = true;
    }
}


int main() {
    init();
    int x, y;
    scanf("%d %d", &m, &n);
    char dir, str[110];
    while (scanf("%d %d %c", &x, &y, &dir) != EOF) {
        scanf("%s", str);
        fell = false;
        for (int i = 0; i < strlen(str) && !fell; ++i) {
            switch (str[i]) {
                case 'R': dir = changeDir(dir, 'R');
                          break;
                case 'L': dir = changeDir(dir, 'L');
                          break;
                case 'F': moveInDir(dir, &x, &y);
                          break;
            }
        }
        printf("%d %d %c", x, y, dir);
        if (fell)
            printf(" LOST");
        printf("\n");
    }
    return 0;
}

/*
Author : bumpy (-_-)
date : 24-Jul-2016
*/
