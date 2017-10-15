#include <bits/stdc++.h>

using namespace std;

//           W,  N, E, S
int dx[] = { 0, -1, 0, 1};
int dy[] = {-1,  0, 1, 0};
int grid[15][15], depth[15][15], m, n, X, Y;

bool hasWall(int x, int y, char dir) {
    switch (dir){
        case 'E':
            return (grid[x][y] == 1 || grid[x][y] == 3);
        case 'S':
            return (grid[x][y] == 2 || grid[x][y] == 3);
    }
}

bool canMove(int x, int y, int dir) {
    if (depth[x + dx[dir]][y + dy[dir]] != 0)
        return false;
    switch (dir) {
        case 0:
            return (y > 0 && !hasWall(x, y-1, 'E')); // West
        case 1:
            return (x > 0 && !hasWall(x-1, y, 'S')); // North
        case 2:
            return (y < n-1 && !hasWall(x, y, 'E')); // East
        case 3:
            return (x < m-1 && !hasWall(x, y, 'S')); // South
    }
}

bool DFS(int x, int y, int d) {
    depth[x][y] = d;
    if (x == X && y == Y) {
        return true;
    }
    for (int i = 0; i < 4; ++i) {
        if (canMove(x, y, i)) {
            int a = x + dx[i];
            int b = y + dy[i];
            bool found = DFS(a, b, d + 1);
            if (found)
                return true;
        }
    }
    depth[x][y] = -1;
    return false;
}

void printDepth(int x, int y) {
    if (depth[x][y] == 0)
        printf("   ");
    else if (depth[x][y] == -1)
        printf("???");
    else
        printf("%3d", depth[x][y]);
}

void printAns() {
    printf("+");
    for (int i = 0; i < n; ++i)
        printf("---+");
    printf("\n");
    for (int i = 0; i < m ; ++i) {
        printf("|");
        for (int j = 0; j < n - 1; ++j) {
            printDepth(i, j);
            printf(hasWall(i, j, 'E') ? "|" : " ");
        }
        printDepth(i, n-1);
        printf("|\n+");
        if (i == m - 1)
            continue;
        for (int j = 0; j < n; ++j) {
            printf(hasWall(i, j, 'S') ? "---+" : "   +");
        }
        printf("\n");
    }
    for (int i = 0; i < n; ++i) {
        printf("---+");
    }
    printf("\n\n\n");
}

int main() {
    int x, y, kk = 1;
    while (scanf("%d %d %d %d %d %d", &m, &n, &x, &y, &X, &Y) && (m | n | x | y | X | Y)) {
        --x, --y, --X, --Y;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &grid[i][j]);
            }
        }
        DFS(x, y, 1);

        // Printing Ans
        printf("Maze %d\n\n", kk++);
        printAns();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                depth[i][j] = 0;
            }
        }
    }
    return 0;
}

/*
Author : bumpy (-_-)
date : 30-Jul-2016
*/
