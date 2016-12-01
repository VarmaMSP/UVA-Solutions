#include <bits/stdc++.h>

using namespace std;

vector< pair<int, int> > res;

int main(){
    int x, y, k;
    while(scanf("%d", &k) != EOF){
        int cnt = 0;
        for(int y = k + 1; y <= 2*k; ++y){
            if((k*y) % (y-k) == 0){
                res.push_back({(k*y)/(y-k), y});
                ++cnt;
            }
        }
        printf("%d\n", cnt);
        for(int i = 0; i < res.size(); ++i)
            printf("1/%d = 1/%d + 1/%d\n", k, res[i].first, res[i].second);
        res.clear();
    }
    return 0;
}

/*
Author : bumpy (-_-)
date : 10-Jul-2016
*/
