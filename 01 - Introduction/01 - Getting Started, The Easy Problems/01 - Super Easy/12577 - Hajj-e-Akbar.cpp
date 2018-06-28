#include <bits/stdc++.h>

using namespace std;

string Hajj = "Hajj";
string Umrah = "Umrah";

int main() {
  int i = 1;
  string str;
  while (cin >> str && str != "*") {
      printf("Case %d: ", i++);
      if (str == Hajj) {
          puts("Hajj-e-Akbar");
      }
      if (str == Umrah) {
          puts("Hajj-e-Asghar");
      }
  }
  return 0;
}

/*
Author: bumpy (-_-)
date: 28-Jun-2018
*/
