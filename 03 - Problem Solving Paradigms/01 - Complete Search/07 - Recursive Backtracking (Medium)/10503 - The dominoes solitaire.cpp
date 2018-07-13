#include <bits/stdc++.h>

using namespace std;

int n, m;
bool isPoss, placed[15];
pair< int, int > l, r, d[15];
vector< pair< int, int > > res;

void solve(int p) {
    if (isPoss) return ;
    if (p < m) {
        int c = (res.rbegin())->second;
        for (int i = 0; i < m; ++i) if (!placed[i]) {
            if (d[i].first == c || d[i].second == c) {
                res.push_back(d[i].first == c ? d[i] : make_pair(d[i].second, d[i].first));
                placed[i] = true;
                solve(p + 1);
                placed[i] = false;
                res.pop_back();
            }
        }
        solve(p + 1);
        return ;
    }
    int c = (res.rbegin())->second;
    if (res.size() >= n && c == r.first) {
        isPoss = true;
    }
}

int main() {
    while (scanf("%d", &n) && n) {
        scanf("%d", &m);
        scanf("%d %d", &l.first, &l.second);
        scanf("%d %d", &r.first, &r.second);
        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &d[i].first, &d[i].second);
        }
        isPoss = false;
        res.push_back(l), solve(0);
        puts(isPoss ? "YES" : "NO");
        res.clear();
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 13-July-2018
*/
