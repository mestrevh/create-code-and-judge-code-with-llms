/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void derivada(int *coeficiente, int *expoente, int numMonomios) {
    vector<string> resultado;
    for (int i = 0; i < numMonomios; i++) {
        if (expoente[i] > 0) {
            int novoCoef = coeficiente[i] * expoente[i];
            int novoExpo = expoente[i] - 1;
            stringstream ss;
            if (novoExpo == 0) {
                ss << (novoCoef > 0 && i != 0 ? "+" : "") << novoCoef;
            } else {
                ss << (novoCoef > 0 && i != 0 ? "+" : "") << novoCoef << "x^" << novoExpo;
            }
            resultado.push_back(ss.str());
        }
    }
    cout << "f'(x)=" << (resultado.empty() ? "0" : "") << (resultado.empty() ? "" : resultado[0]);
    for (size_t j = 1; j < resultado.size(); j++) {
        cout << resultado[j];
    }
    cout << endl;
}

int main() {
    while (true) {
        int numMonomios;
        cin >> numMonomios;
        if (numMonomios == 0) break;

        int *coeficiente = new int[numMonomios];
        int *expoente = new int[numMonomios];

        for (int i = 0; i < numMonomios; i++) {
            cin >> coeficiente[i] >> ws; // Read coefficient
            string variable;
            cin >> variable; // Read variable (e.g., x)
            cin >> expoente[i]; // Read exponent
        }

        derivada(coeficiente, expoente, numMonomios);

        delete[] coeficiente;
        delete[] expoente;
    }
    return 0;
}
