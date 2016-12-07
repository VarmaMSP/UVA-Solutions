#include <bits/stdc++.h>

using namespace std;

int degree[26];

int main(){
    int tt, k = 1;
    cin >> tt;
    string str;
    while(tt--){
        cin >> str;
        stack<char> S;
        for(int i = 0; i < str.size(); ++i){
            if(S.empty()){
                S.push(str[i]);
                continue;
            }
            if(S.top() == str[i]){
                S.pop();
                if(!S.empty()){
                    degree[str[i]  - 'A']++;
                    degree[S.top() - 'A']++;
                }
            } else {
                S.push(str[i]);
            }
        }
        printf("Case %d\n", k++);
        for(int i = 0; i < 26; ++i) if(degree[i] > 0)
            printf("%c = %d\n", (char)('A' + i), degree[i]);
        memset(degree, 0, sizeof(degree));
    }
    return 0;
}

/*
Author : bumpy (-_-)
date : 24-Jul-2016
*/
