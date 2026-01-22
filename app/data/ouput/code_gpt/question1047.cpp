/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

double mediaAritmetica(const vector<double>& notas) {
    return (notas[0] + notas[1] + notas[2]) / 3.0;
}

double mediaPonderada(const vector<double>& notas, const vector<double>& pesos) {
    double somaNotas = notas[0] * pesos[0] + notas[1] * pesos[1] + notas[2] * pesos[2];
    double somaPesos = pesos[0] + pesos[1] + pesos[2];
    return somaNotas / somaPesos;
}

double mediaHarmonica(const vector<double>& notas) {
    return 3.0 / ((1.0 / notas[0]) + (1.0 / notas[1]) + (1.0 / notas[2]));
}

int main() {
    vector<double> notas(3), pesos(3);
    
    for (int i = 0; i < 3; i++) {
        cin >> notas[i];
    }
    
    for (int i = 0; i < 3; i++) {
        cin >> pesos[i];
    }
    
    cout << fixed << setprecision(1);
    cout << "a: " << mediaAritmetica(notas) << endl;
    cout << "p: " << mediaPonderada(notas, pesos) << endl;
    cout << "h: " << mediaHarmonica(notas) << endl;

    return 0;
}
