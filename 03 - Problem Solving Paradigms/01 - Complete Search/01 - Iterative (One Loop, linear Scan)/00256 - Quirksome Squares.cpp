#include <bits/stdc++.h>

using namespace std;

typedef long long int i64;

i64 square[20000];

void preComp(){
    for(int i = 0; i <= 20000; ++i)
        square[i] = i*i;
}

int main(){
    preComp();
    int n;
    while(scanf("%d", &n) != EOF){
        int x = pow(10, n/2);
        int y = pow(10, n);
        for(int i = 0; i < y; ++i) {
            if(square[(i/x + i%x)] == i)
                cout << setw(n) << setfill('0') << i << endl;
        }
    }
    return 0;
}

/*
Author : bumpy (-_-)
date : 10-Jul-2016
*/

