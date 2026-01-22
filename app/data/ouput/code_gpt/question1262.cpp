/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int N;
    cin >> N;
    double notas[N], pesos[N], somaNotas = 0, somaPesos = 0;

    for (int i = 0; i < N; i++) {
        cin >> notas[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> pesos[i];
    }
    
    for (int i = 0; i < N; i++) {
        somaNotas += notas[i] * pesos[i];
        somaPesos += pesos[i];
    }

    double media = somaNotas / somaPesos;
    cout << fixed << setprecision(2) << media << endl;

    return 0;
}
