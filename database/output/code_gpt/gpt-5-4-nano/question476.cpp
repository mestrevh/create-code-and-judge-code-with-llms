/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X;
    if (!(cin >> X)) return 0;

    for (int i = 0; i < X; i++) {
        string nome;
        cin >> ws;
        getline(cin, nome);
        long long ID, Level, Vida, Ataque, Defesa;
        cin >> ID >> Level >> Vida >> Ataque >> Defesa;

        cout << "Nome: " << nome << "\n";
        cout << "ID: " << ID << "\n";
        cout << "Level: " << Level << "\n";
        cout << "Vida: " << Vida << "\n";
        cout << "Ataque: " << Ataque << "\n";
        cout << "Defesa: " << Defesa;
        if (i + 1 < X) cout << "\n";
    }
    return 0;
}