/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text;
    if (!getline(cin, text)) return 0;

    string a, b;
    getline(cin, a);
    getline(cin, b);

    if (a.empty()) {
        cout << text << "\n";
        return 0;
    }

    size_t pos = 0;
    while ((pos = text.find(a, pos)) != string::npos) {
        text.replace(pos, a.size(), b);
        pos += b.size();
    }

    cout << text << "\n";
    return 0;
}