/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char bairro;
    double renda, consumo;

    if (!(cin >> bairro)) return 0;
    if (!(cin >> renda >> consumo)) return 0;

    if (bairro != 'S' && bairro != 'I' && bairro != 'T') {
        cout << "Bairro invalido." << endl;
        return 0;
    }

    if (renda < 0 || consumo < 0) {
        cout << "Renda e consumo nao podem ser negativos." << endl;
        return 0;
    }

    double percentual_desconto = 0.0;

    if (bairro == 'S') {
        if (renda <= 900.0) {
            percentual_desconto = 0.20;
        } else if (renda <= 1500.0) {
            percentual_desconto = 0.10;
        }
    } else if (bairro == 'I') {
        if (renda <= 500.0) {
            percentual_desconto = 0.15;
        } else if (renda <= 1000.0) {
            percentual_desconto = 0.10;
        }
    } else if (bairro == 'T') {
        if (renda <= 1000.0) {
            percentual_desconto = 0.20;
        } else if (renda <= 2000.0) {
            percentual_desconto = 0.10;
        }
    }

    double valor_final = consumo * (1.0 - percentual_desconto);

    cout << fixed << setprecision(2) << valor_final << endl;

    return 0;
}