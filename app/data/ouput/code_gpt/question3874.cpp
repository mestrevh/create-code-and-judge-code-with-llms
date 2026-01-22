/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct Cincabeca {
    int idade;
    int id;
    string nome;
};

bool isPrimo(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}

bool isQuadradoPerfeito(int n) {
    int r = sqrt(n);
    return r * r == n;
}

int calcularPontos(Cincabeca &c) {
    int pontos = 0;
    if (isPrimo(c.idade)) pontos += 4;
    if (isQuadradoPerfeito(c.id)) pontos += 3;
    return pontos;
}

int main() {
    Cincabeca c1, c2;
    cin >> c1.idade >> c1.id >> ws;
    getline(cin, c1.nome);
    cin >> c2.idade >> c2.id >> ws;
    getline(cin, c2.nome);

    int pontos1 = calcularPontos(c1);
    int pontos2 = calcularPontos(c2);

    if (c1.nome > c2.nome) pontos1 += 2;
    else if (c1.nome < c2.nome) pontos2 += 2;

    if (pontos1 > pontos2) cout << c1.nome << " WINS" << endl;
    else if (pontos2 > pontos1) cout << c2.nome << " WINS" << endl;
    else cout << "CInCABECAS EMPATADOS" << endl;

    return 0;
}
