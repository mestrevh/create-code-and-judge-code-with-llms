/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a > b && a > c) {
        cout << "O vencedor é Introducao a Programacao com um total de " << a << " votos E O HEXA VEIO." << endl;
    } else if (b > a && b > c) {
        cout << "O vencedor é Introducao a Computacao com um total de " << b << " votos." << endl;
    } else if (c > a && c > b) {
        cout << "O vencedor é Calculo 6 com um total de " << c << " votos." << endl;
    } else {
        cout << "Empate." << endl;
    }

    return 0;
}
