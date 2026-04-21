/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, line;
    bool first = true;
    while (std::getline(cin, line)) {
        if (!first) s.push_back('\n');
        s += line;
        first = false;
    }
    if (s.empty() && !cin) return 0;

    unordered_map<char, char> mp = {
        {'a','4'}, {'A','4'},
        {'e','3'}, {'E','3'},
        {'i','1'}, {'I','1'},
        {'o','0'}, {'O','0'},
        {'u','5'}, {'U','5'}
    };

    for (char &c : s) {
        auto it = mp.find(c);
        if (it != mp.end()) c = it->second;
    }

    cout << s;
    return 0;
}