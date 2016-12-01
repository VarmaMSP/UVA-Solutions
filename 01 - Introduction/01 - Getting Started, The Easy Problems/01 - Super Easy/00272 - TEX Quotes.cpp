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

/*
Author : bumpy (-_-)
date : 30-Nov-2016
*/
