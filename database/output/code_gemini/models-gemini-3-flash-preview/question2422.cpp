/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double valorMax;
    if (!(cin >> valorMax)) return 0;
    
    string moeda1;
    if (!(cin >> moeda1)) return 0;

    double somaItens = 0;
    for (int i = 0; i < 4; ++i) {
        string objeto;
        double valor;
        if (!(cin >> objeto >> valor)) break;
        somaItens += valor;
    }

    string moeda2;
    if (!(cin >> moeda2)) return 0;

    bool m1_valida = (moeda1 == "real" || moeda1 == "iene");
    bool m2_valida = (moeda2 == "real" || moeda2 == "iene");

    if (!m1_valida || !m2_valida) {
        cout << "Nao conheco essa moeda, vamos comprar outra coisa..." << endl;
        return 0;
    }

    double totalConvertido;
    if (moeda1 == moeda2) {
        totalConvertido = somaItens;
    } else if (moeda1 == "real" && moeda2 == "iene") {
        // Converting items from iene to real
        totalConvertido = somaItens * 0.03;
    } else {
        // Converting items from real to iene (moeda1 is iene, moeda2 is real)
        // 1 iene = 0.03 reais -> 1 real = 1/0.03 ienes
        totalConvertido = somaItens / 0.03;
    }

    // Floating point comparison with epsilon
    if (totalConvertido <= valorMax + 1e-9) {
        cout << "UHU, todo trabalho valeu a pena!" << endl;
    } else {
        cout << "Nao podemos comprar tudo, precisamos codar mais." << endl;
    }

    return 0;
}