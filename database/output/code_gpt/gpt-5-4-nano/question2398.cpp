/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!getline(cin, s)) return 0;

    for (char &c : s) if (c == '\r' || c == '\n') c = ' ';

    int dd, mm, aa;
    char c1, c2;
    stringstream ss(s);
    ss >> dd >> c1 >> mm >> c2 >> aa;

    cout << setw(2) << setfill('0') << mm << "/" << setw(2) << setfill('0') << dd << "/" << setw(2) << setfill('0') << aa << "\n";
    cout << setw(2) << setfill('0') << aa << "/" << setw(2) << setfill('0') << mm << "/" << setw(2) << setfill('0') << dd << "\n";
    cout << setw(2) << setfill('0') << dd << "-" << setw(2) << setfill('0') << mm << "-" << setw(2) << setfill('0') << aa << "\n";

    return 0;
}