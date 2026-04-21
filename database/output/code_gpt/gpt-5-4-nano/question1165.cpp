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
    getline(cin, s);

    auto printErrorAndZero = [&]() {
        cout << "numeros\n0";
    };

    if (s.empty()) {
        cout << "erro\n0";
        return 0;
    }

    for (char c : s) {
        if (c >= '0' && c <= '9') {
            printErrorAndZero();
            return 0;
        }
    }

    unordered_map<char, char> mp;
    mp['a'] = '@'; mp['A'] = '@';
    mp['e'] = '3'; mp['E'] = '3';
    mp['i'] = '1'; mp['I'] = '1';
    mp['o'] = '0'; mp['O'] = '0';
    mp['t'] = '7'; mp['T'] = '7';
    mp['s'] = '5'; mp['S'] = '5';

    long long cnt = 0;
    for (char &c : s) {
        auto it = mp.find(c);
        if (it != mp.end()) {
            c = it->second;
            cnt++;
        }
    }

    cout << s << "\n" << cnt;
    return 0;
}