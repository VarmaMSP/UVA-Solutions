#include <bits/stdc++.h>

using namespace std;

typedef tuple< int, int, int, int > Ti4;

int dist[10][10][10][10];
bool visit[10][10][10][10], forbid[10][10][10][10];

inline int left(int a) { return (a + 1) % 10; }
inline int right(int a) { return (a + 9) % 10; }

int bfs(Ti4 s, Ti4 des) {
    queue< Ti4 > Q;
    int a = get<0>(s), b = get<1>(s);
    int c = get<2>(s), d = get<3>(s);
    dist[a][b][c][d] = 0;
    visit[a][b][c][d] = true;
    Q.push(s);
    while (!Q.empty()) {
        Ti4 u = Q.front(); Q.pop();
        a = get<0>(u), b = get<1>(u);
        c = get<2>(u), d = get<3>(u);
        if (u == des) {
            return dist[a][b][c][d];
        }
        Ti4 v[8];
        v[0] = {left(a), b, c, d}, v[1] = {right(a), b, c, d};
        v[2] = {a, left(b), c, d}, v[3] = {a, right(b), c, d};
        v[4] = {a, b, left(c), d}, v[5] = {a, b, right(c), d};
        v[6] = {a, b, c, left(d)}, v[7] = {a, b, c, right(d)};
        for (int i = 0; i < 8; ++i) {
            int A = get<0>(v[i]);
            int B = get<1>(v[i]);
            int C = get<2>(v[i]);
            int D = get<3>(v[i]);
            if (!visit[A][B][C][D] && !forbid[A][B][C][D]) {
                dist[A][B][C][D] = dist[a][b][c][d] + 1;
                visit[A][B][C][D] = true;
                Q.push(v[i]);
            }
        }
    }
    return -1;
}

int main() {
    Ti4 src, des;
    int tt, f, a, b, c, d;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        src = {a, b, c, d};
        scanf("%d %d %d %d", &a, &b, &c, &d);
        des = {a, b, c, d};
        scanf("%d", &f);
        while (f--) {
            scanf("%d %d %d %d", &a, &b, &c, &d);
            forbid[a][b][c][d] = true;
        }
        printf("%d\n", bfs(src, des));
        memset(visit, false, sizeof(visit));
        memset(forbid, false, sizeof(forbid));
    }
    return 0;
}
