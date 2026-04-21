/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, c, br, nu;
    long long totalA = 0, totalB = 0, totalC = 0, totalBr = 0, totalNu = 0;
    long long sec = 1;
    while (true) {
        long long s;
        if (!(cin >> s)) break;
        if (s == 0) break;
        cin >> a >> b >> c >> br >> nu;
        totalA += a;
        totalB += b;
        totalC += c;
        totalBr += br;
        totalNu += nu;
        sec++;
    }

    long long votantes = totalA + totalB + totalC + totalBr + totalNu;
    long long validos = totalA + totalB + totalC;
    string cand;
    if (validos == 0) {
        cand = "";
    } else {
        long long mx = max({totalA, totalB, totalC});
        if (totalC == mx) cand = "C";
        else if (totalB == mx) cand = "B";
        else cand = "A";
    }

    bool eleicaoValida = (totalBr + totalNu) < validos;
    bool segundoTurno = false;
    if (validos > 0 && !eleicaoValida) {
        segundoTurno = true;
    } else if (validos > 0) {
        long long mx = max({totalA, totalB, totalC});
        segundoTurno = !(mx > validos / 2);
    } else {
        segundoTurno = false;
    }

    cout << "Numero de votantes: " << votantes << "\n";
    cout << "Total A: " << totalA << "\n";
    cout << "Total B: " << totalB << "\n";
    cout << "Total C: " << totalC << "\n";
    cout << "Brancos: " << totalBr << "\n";
    cout << "Nulos: " << totalNu << "\n";
    cout << "Validos: " << validos << "\n";
    cout << "Candidato mais votado: " << cand << "\n";
    cout << "Eleicao valida? " << (eleicaoValida ? "True" : "False") << "\n";
    cout << "Segundo turno? " << (segundoTurno ? "True" : "False") << "\n";
    return 0;
}