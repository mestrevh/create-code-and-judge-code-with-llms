/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    if (!getline(cin, a)) return 0;
    if (!getline(cin, b)) b = "";

    vector<bool> remove(256, false);
    for (unsigned char ch : b) remove[ch] = true;

    string res;
    res.reserve(a.size());
    for (unsigned char ch : a) {
        if (!remove[ch]) res.push_back((char)ch);
    }

    cout << res << "\n";
    return 0;
}