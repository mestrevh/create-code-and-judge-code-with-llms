/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int votosA, votosB, votosC, votosNulos;
    cin >> votosA >> votosB >> votosC >> votosNulos;

    int totalVotos = votosA + votosB + votosC + votosNulos;

    cout << "Candidato A: " << (votosA * 100) / totalVotos << "%" << endl;
    cout << "Candidato B: " << (votosB * 100) / totalVotos << "%" << endl;
    cout << "Candidato C: " << (votosC * 100) / totalVotos << "%" << endl;
    cout << "Nulos: " << (votosNulos * 100) / totalVotos << "%" << endl;

    return 0;
}
