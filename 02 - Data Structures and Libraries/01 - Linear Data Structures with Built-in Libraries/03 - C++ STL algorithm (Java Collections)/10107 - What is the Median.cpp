#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, l = 0;
    vector< int > a;
    while (scanf("%d", &x) != EOF) {
        ++l;
        a.push_back(x);
        
        int j = l - 2;
        while (j >= 0 && a[j] > x) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = x;

        int median = a[l/2];
        if (l % 2 == 0) {
            median += a[l/2 + 1];
            median /= 2;
        }
        printf("%d\n", median); 
    }
    return 0;
}
