/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    int valorMax;
    string moeda1, moeda2;
    cin >> valorMax >> moeda1;

    int total = 0;
    for (int i = 0; i < 4; ++i) {
        string objeto;
        int valor;
        cin >> objeto >> valor;
        total += valor;
    }
    cin >> moeda2;

    if ((moeda1 == "real" && moeda2 == "real") || (moeda1 == "iene" && moeda2 == "iene")) {
        if (total <= valorMax) {
            cout << "UHU, todo trabalho valeu a pena!" << endl;
        } else {
            cout << "Nao podemos comprar tudo, precisamos codar mais." << endl;
        }
    } else if (moeda1 == "iene" && moeda2 == "real") {
        if (total * 0.03 <= valorMax) {
            cout << "UHU, todo trabalho valeu a pena!" << endl;
        } else {
            cout << "Nao podemos comprar tudo, precisamos codar mais." << endl;
        }
    } else if (moeda1 == "real" && moeda2 == "iene") {
        if (total <= valorMax * 100) {
            cout << "UHU, todo trabalho valeu a pena!" << endl;
        } else {
            cout << "Nao podemos comprar tudo, precisamos codar mais." << endl;
        }
    } else {
        cout << "Nao conheco essa moeda, vamos comprar outra coisa..." << endl;
    }
    
    return 0;
}
