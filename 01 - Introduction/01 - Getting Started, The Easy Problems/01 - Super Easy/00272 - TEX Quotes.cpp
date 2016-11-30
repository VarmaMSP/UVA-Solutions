#include <bits/stdc++.h>

int main() {
    char c;
    bool open = true;
    while (scanf("%c", &c) != EOF) {
        if (c == '"') {
            if (open)
                printf("``");
            else
                printf("''");
            open = !open;
        }
        else {
            printf("%c", c);
        }
    }
    return 0;
}

//Date: 30 Nov, 2016
//Author: bumpy -_-
