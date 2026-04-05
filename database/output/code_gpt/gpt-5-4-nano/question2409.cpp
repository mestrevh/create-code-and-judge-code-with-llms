/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string nome, sobrenome;
    if (!getline(cin, nome)) return 0;
    if (!getline(cin, sobrenome)) return 0;

    auto trim = [](string &s) {
        size_t start = s.find_first_not_of(" \t\r\n");
        size_t end = s.find_last_not_of(" \t\r\n");
        if (start == string::npos) s.clear();
        else s = s.substr(start, end - start + 1);
    };

    trim(nome);
    trim(sobrenome);

    cout << nome << ' ' << sobrenome;
    return 0;
}