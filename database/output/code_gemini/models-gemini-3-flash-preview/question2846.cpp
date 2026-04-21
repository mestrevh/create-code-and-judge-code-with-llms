/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double total_value = 0.0;
    int total_exchanged = 0;

    cout << "Insira a quantidade e valor de cada presente:" << endl;

    for (int i = 0; i < 6; ++i) {
        double value;
        int quantity;
        if (!(cin >> value >> quantity)) break;
        
        if (quantity > 1) {
            int exchanged = quantity - 1;
            total_exchanged += exchanged;
            total_value += (value * exchanged);
        }
    }

    cout << "Numero de presentes a serem trocados: " << total_exchanged << endl;

    if (total_value >= 800.0) {
        cout << "Voce PODERA adquirir o ar condicionado com as trocas" << endl;
    } else {
        cout << "Voce NAO PODERA adquirir o ar condicionado com as trocas" << endl;
    }

    return 0;
}