/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int inscritos = 0, aprovados = 0, mulheresA = 0, homensA = 0;

    while (true) {
        int obj;
        if (!(cin >> obj)) break;
        if (obj < 0) break;

        while (obj > 100) {
            cout << "Digite uma nota inferior a 100.\n";
            cin >> obj;
            if (obj < 0) break;
        }
        if (obj < 0) break;

        int red;
        cin >> red;
        while (red > 100) {
            cout << "Digite uma nota inferior a 100.\n";
            cin >> red;
        }

        char sexo;
        cin >> sexo;

        inscritos++;
        bool okObj = obj > 40;
        bool okMedia = (obj + red) / 2.0 >= 60.0;

        if (okObj && okMedia) {
            aprovados++;
            if (sexo == 'F') mulheresA++;
            else if (sexo == 'M') homensA++;
        }
    }

    cout << inscritos << " candidato(s) inscrito(s).\n";
    cout << aprovados << " candidato(s) aprovado(s).\n";
    cout << mulheresA << " mulher(es) e " << (aprovados - mulheresA) << " homem(ns).\n";

    return 0;
}