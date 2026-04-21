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
    while (!s.empty() && (s.back() == '\r' || s.back() == '\n')) s.pop_back();
    if (s.empty()) return 0;

    unordered_map<char, int> val{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    long long total = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        char c = s[i];
        long long v = val[c];
        long long next = (i + 1 < (int)s.size()) ? val[s[i + 1]] : 0;
        if (v < next) total -= v;
        else total += v;
    }

    if (total % 5 == 0) {
        cout << "O numero e multiplo de 5!\n";
    } else {
        cout << "O resto pela divisao por 5 do numero dado e igual a " << (total % 5) << "!\n";
    }
    return 0;
}