/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double D;
    if (!(cin >> D)) return 0;

    string line;
    string rest;
    long long total = 0;

    auto trim = [](string &s) {
        while (!s.empty() && isspace((unsigned char)s.back())) s.pop_back();
        size_t i = 0;
        while (i < s.size() && isspace((unsigned char)s[i])) i++;
        if (i) s.erase(0, i);
    };

    while (true) {
        string curso;
        if (!(cin >> curso)) break;
        getline(cin, rest);
        trim(rest);
        if (curso == "CC") total += 5;
        else if (curso == "EC") total += 10;
        else total += 15;
    }

    cout << (D >= (double)total ? "Cebruthius!" : "Escamou!");
    return 0;
}