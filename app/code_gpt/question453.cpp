/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    map<string, double> precos = {
        {"morango / cereja", 4.50},
        {"damasco / siriguela", 3.80},
        {"outros sabores", 2.75}
    };

    string sabor;
    int quantidade;
    
    getline(cin, sabor);
    cin >> quantidade;
    
    transform(sabor.begin(), sabor.end(), sabor.begin(), ::tolower);

    double total = 0.0;
    if (precos.find(sabor) != precos.end()) {
        total = precos[sabor] * quantidade;
        cout << fixed << setprecision(2) << total << endl;
        if (quantidade > 2) {
            cout << "COM CALDA" << endl;
        } else {
            cout << "SEM CALDA" << endl;
        }
    } else {
        cout << "Sabor inválido." << endl;
    }

    return 0;
}
