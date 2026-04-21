/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string L, M, S;
    if (!(cin >> L >> M >> S)) return 0;

    auto ok = [](const string& x) -> bool {
        if (x.empty()) return false;
        char first = x.front();
        char last = x.back();
        string target = "Fortaleza do Bowser";
        char tfirst = target.front();
        char tlast = target.back();
        return first == tfirst && last == tlast;
    };

    bool leftOk = ok(L);
    bool midOk = ok(M);
    bool rightOk = ok(S);

    if (rightOk) cout << "Direita\n";
    else if (midOk) cout << "Meio\n";
    else if (leftOk) cout << "Esquerda\n";
    else cout << "Vou em frente\n";

    return 0;
}