#include <bits/stdc++.h>

using namespace std;

typedef tuple< int, int, int, int > Ti4;

int ca, cb, cc, D;
int d[201][201][201], dd[201];

void dijkstra(int x, int y, int z) {
    priority_queue< Ti4, vector< Ti4 >, greater< Ti4 > > Q;
    d[x][y][z] = 0;
    Q.push({d[x][y][z], x, y, z});
    while (!Q.empty()) {
        Ti4 u = Q.top(); Q.pop();
        int a = get<1>(u);
        int b = get<2>(u);
        int c = get<3>(u), amt;
        // a to b
        if (a > 0) {
            int A = a + b > cb ? a - cb + b : 0;
            int B = a + b > cb ? cb : a + b;
            amt = B - b;
            if (d[A][B][c] > d[a][b][c] + amt) {
                d[A][B][c] = d[a][b][c] + amt;
                Q.push({d[A][B][c], A, B, c});
            }
        }
        // a to c
        if (a > 0) {
            int A = a + c > cc ? a - cc + c : 0;
            int C = a + c > cc ? cc : a + c;
            amt = C - c;
            if (d[A][b][C] > d[a][b][c] + amt) {
                d[A][b][C] = d[a][b][c] + amt;
                Q.push({d[A][b][C], A, b, C});
            }
        }
        // b to a
        if (b > 0) {
            int A = a + b > ca ? ca : a + b;
            int B = a + b > ca ? b - ca + a : 0;
            amt = A - a;
            if (d[A][B][c] > d[a][b][c] + amt) {
                d[A][B][c] = d[a][b][c] + amt;
                Q.push({d[A][B][c], A, B, c});
            }
        }
        // b to c
        if (b > 0) {
            int B = b + c > cc ? b - cc + c : 0;
            int C = b + c > cc ? cc : b + c;
            amt = C - c;
            if (d[a][B][C] > d[a][b][c] + amt) {
                d[a][B][C] = d[a][b][c] + amt;
                Q.push({d[a][B][C], a, B, C});
            }
        }
        // c to a
        if (c > 0) {
            int A = a + c > ca ? ca : a + c;
            int C = a + c > ca ? c - ca + a : 0;
            amt = A - a;
            if (d[A][b][C] > d[a][b][c] + amt) {
                d[A][b][C] = d[a][b][c] + amt;
                Q.push({d[A][b][C], A, b, C});
            }
        }
        // c to b
        if (c > 0) {
            int B = b + c > cb ? cb : b + c;
            int C = b + c > cb ? c - cb + b : 0;
            amt = B - b;
            if (d[a][B][C] > d[a][b][c] + amt) {
                d[a][B][C] = d[a][b][c] + amt;
                Q.push({d[a][B][C], a, B, C});
            }
        }
        if (a <= D) dd[a] = min(dd[a], d[a][b][c]);
        if (b <= D) dd[b] = min(dd[b], d[a][b][c]);
        if (c <= D) dd[c] = min(dd[c], d[a][b][c]);
    }
}

int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d %d %d %d", &ca, &cb, &cc, &D);
        for (int i = 0; i <= 200; ++i) {
            dd[i] = INT_MAX;
        }
        for (int i = 0; i <= cc; ++i) {
            for (int j = 0; j <= cc; ++j) {
                for (int k = 0; k <= cc; ++k) {
                    d[i][j][k] = INT_MAX;
                }
            }
        }
        dijkstra(0, 0, cc);
        for (int i = D; i >= 0; --i) {
            if (dd[i] != INT_MAX) {
                printf("%d %d\n", dd[i], i);
                break;
            }
        }
    }
    return 0;
}
