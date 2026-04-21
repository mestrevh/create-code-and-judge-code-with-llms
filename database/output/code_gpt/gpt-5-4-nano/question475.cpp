/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> names(10);
    for (int i = 0; i < 10; i++) {
        if (!getline(cin, names[i])) return 0;
        if (names[i].size() == 0) i--;
    }

    char target;
    string line;
    if (!(cin >> target)) return 0;

    char t = (char)tolower((unsigned char)target);

    for (int i = 0; i < 10; i++) {
        string s = names[i];
        for (char &c : s) c = (char)tolower((unsigned char)c);
        if (s.find(t) != string::npos) {
            cout << names[i] << "\n";
        }
    }
    return 0;
}