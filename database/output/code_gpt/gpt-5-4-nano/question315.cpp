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
    if (!(cin >> s)) return 0;

    string hex = s;
    string valid = "0123456789ABCDEF";

    for (char &ch : hex) {
        if (valid.find(ch) == string::npos) ch = '0';
    }

    while ((int)hex.size() % 3 != 0) hex.push_back('0');

    while ((int)hex.size() < 12) hex.push_back('0');

    if ((int)hex.size() > 12) hex = hex.substr(0, 12);

    int group = (int)hex.size() / 3;
    auto toVal = [&](int idx) -> int {
        string part = hex.substr(idx * group, group);
        if (part.size() > 2) part = part.substr(part.size() - 2);
        if (part.empty()) part = "0";
        return stoi(part, nullptr, 16);
    };

    int r = toVal(0);
    int g = toVal(1);
    int b = toVal(2);

    cout << "(" << r << "," << g << "," << b << ")\n";
    return 0;
}