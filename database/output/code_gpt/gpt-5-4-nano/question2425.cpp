/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string seat1, seat2, seat3a, seat3b;
    int aluno;
    if (!(cin >> seat1)) return 0;
    cin >> seat2;
    cin >> aluno;
    cin >> seat3a >> seat3b;

    auto lineOf = [](const string& s) -> char {
        if (s.empty()) return ' ';
        return s[0];
    };

    char refLine = (aluno == 1) ? lineOf(seat1) : lineOf(seat2);
    char l1 = lineOf(seat3a);
    char l2 = lineOf(seat3b);

    int d1 = abs(l1 - refLine);
    int d2 = abs(l2 - refLine);

    if (d1 < d2) {
        cout << "A opcao 1 e a mais segura";
    } else if (d2 < d1) {
        cout << "A opcao 2 e a mais segura";
    } else {
        cout << "Vou fechar os olhos e decidir.";
    }
    return 0;
}