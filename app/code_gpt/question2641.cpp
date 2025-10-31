/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int horasNecessarias(int E, int X, int N, int horas) {
    int total = N * (X + 100 * horas);
    if (total >= E) return horas;
    return horasNecessarias(E, X, N, horas + 1);
}

int main() {
    int E, X, N;
    cin >> E >> X >> N;
    int horas = horasNecessarias(E, X, N, 0);
    cout << "Precisamos de " << horas << " horas para conseguirmos imprimir " << E << " euros." << endl;
    return 0;
}
