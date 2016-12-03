#include <bits/stdc++.h>

using namespace std;

vector< pair< int, pair< int, int > > > edge;
map< string, int > cityId;
int p[2010];

int find_set(int x) {
    if (p[x] != x)
        p[x] = find_set(p[x]);
    return p[x];
}

int main() {
    int tt, m, n, w;
    string u, v;
    cin >> tt;
    while (tt--) {
        cin >> m >> n;
        int id = 0;
        for (int i = 0; i < n; ++i) {
            cin >> u >> v >> w;
            if (cityId.find(u) == cityId.end())
                cityId[u] = id++;
            if (cityId.find(v) == cityId.end())
                cityId[v] = id++;
            edge.push_back({w, {cityId[u], cityId[v]}});
        }
        for (int i = 0; i < id; ++i) {
            p[i] = i;
        }
        sort(edge.begin(), edge.end());
        int res = 0;
        for (const auto& e: edge) {
            int x = find_set(e.second.first);
            int y = find_set(e.second.second);
            if (x != y) {
                res += e.first;
                p[y] = x;
            }
        }
        cityId.clear();
        edge.clear();
        cout << res << endl;
        if (tt)
            cout << endl;
    }
    return 0;
}
