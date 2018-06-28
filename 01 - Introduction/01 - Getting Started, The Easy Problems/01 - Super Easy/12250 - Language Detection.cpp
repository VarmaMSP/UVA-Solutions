#include <bits/stdc++.h>

using namespace std;

string english = "HELLO";
string spanish = "HOLA";
string german = "HALLO";
string french = "BONJOUR";
string italian = "CIAO";
string russian = "ZDRAVSTVUJTE";

int main() {
    int i = 1;
    string str;
    while (cin >> str && str != "#") {
        printf("Case %d: ", i++);
        if (str == english) puts("ENGLISH");
        else if (str == spanish) puts("SPANISH");
        else if (str == german)  puts("GERMAN");
        else if (str == french)  puts("FRENCH");
        else if (str == italian) puts("ITALIAN");
        else if (str == russian) puts("RUSSIAN");
        else puts("UNKNOWN");
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 28-Jun-2018
*/
