#include <bits/stdc++.h>

using namespace std;

vector< pair< string, string > > book;

pair<string, string> splitString(String tmp) {

}

void readBooks() {
    string tmp, title, author;
    while (cin >> tmp && tmp != "END") {
        book.push_back(splitString(tmp));
    }
    sort(book.begin(), book.end());
}

int main() {

    return 0;
}
