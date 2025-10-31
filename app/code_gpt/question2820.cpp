/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    double distancias[7];
    int diasCumpridos = 0;
    
    cout << "Digite as distancias percorridas separadas por ENTER" << endl;
    for (int i = 0; i < 7; i++) {
        cin >> distancias[i];
        if (distancias[i] >= 8.0) diasCumpridos++;
    }

    cout << "Meta alcancada em " << diasCumpridos << " dias" << endl;
    
    if (diasCumpridos >= 5) {
        cout << "Desempenho otimo" << endl;
    } else if (diasCumpridos >= 3) {
        cout << "Desempenho bom" << endl;
    } else {
        cout << "Desempenho ruim" << endl;
    }

    return 0;
}
