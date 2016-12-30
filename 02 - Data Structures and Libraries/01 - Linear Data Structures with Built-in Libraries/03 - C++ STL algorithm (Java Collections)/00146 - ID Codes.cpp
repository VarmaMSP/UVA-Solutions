#include <bits/stdc++.h>

using namespace std;

bool nextPermutation(char *s) {
    int i, j, l;
    l = strlen(s);
    i = l - 1;
    while (i >= 0 && s[i] >= s[i + 1]) {
        --i;
    }
    if (i < 0) {
        return false;
    }
    j = l - 1;
    while (j > i && s[i] >= s[j]) {
        --j;
    }
    swap(s[i], s[j]);
    sort (s + i + 1, s + l);
    return true;
}

int main() {
    char str[110];
    while (gets(str) && str[0] != '#') {
        if (nextPermutation(str)) {
            puts(str);
        } else {
            puts("No Successor");
        }
    }
    return 0;
}

    
