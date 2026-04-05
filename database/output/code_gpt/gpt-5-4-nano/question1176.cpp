/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string A, D;
    if (!getline(cin, A)) return 0;
    getline(cin, D);

    auto trim = [](string s) {
        size_t start = s.find_first_not_of(" \t\r\n");
        size_t end = s.find_last_not_of(" \t\r\n");
        if (start == string::npos) return string();
        return s.substr(start, end - start + 1);
    };
    A = trim(A);
    D = trim(D);

    if (A == D) {
        cout << "Empate";
        return 0;
    }

    map<string, string> win; // attack -> defense it beats
    win["Fogo"] = "Planta";
    win["Planta"] = "Agua";
    win["Agua"] = "Fogo";
    // Default: if not in cycle, treat as no advantage (shouldn't happen with given problem set)

    if (win.count(A) && win[A] == D) cout << "Vantagem";
    else cout << "Desvantagem";

    return 0;
}