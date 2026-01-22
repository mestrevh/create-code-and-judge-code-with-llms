/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<double> notas(n);
    double soma = 0.0;
    
    for (int i = 0; i < n; i++) {
        cin >> notas[i];
        soma += notas[i];
    }
    
    double media = soma / n;
    double limSuperior = media * 1.1;
    double limInferior = media * 0.9;
    
    int acima = 0, abaixo = 0;
    
    for (double nota : notas) {
        if (nota > limSuperior) acima++;
        if (nota < limInferior) abaixo++;
    }
    
    cout << fixed << setprecision(2) << media << endl;
    cout << acima << endl;
    cout << abaixo << endl;

    return 0;
}
