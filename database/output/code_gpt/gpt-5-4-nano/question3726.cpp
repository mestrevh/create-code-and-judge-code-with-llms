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
    while (getline(cin, line)) {
        if (!s.empty()) s += "\n";
        s += line;
    }
    if (s.empty()) return 0;

    vector<long long> a;
    for (char &c : s) {
        if (c == ',' || c == '[' || c == ']') c = ' ';
    }

    stringstream ss(s);
    long long x;
    while (ss >> x) a.push_back(x);

    bool ordered = true;
    for (size_t i = 1; i < a.size(); ++i) {
        if (a[i-1] > a[i]) {
            ordered = false;
            break;
        }
    }

    cout << (ordered ? "Ordenado" : "Nao ordenado");
    return 0;
}