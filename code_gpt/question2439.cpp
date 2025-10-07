/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int D, G, P;
    cin >> D >> G >> P;

    int totalGas = G;
    int abastecimentos = 0;

    for (int i = 20; i <= D; i += 20) {
        if (totalGas < i) {
            cout << "Xii... Acho que nao vai dar pra te ver, Jasmine" << endl;
            return 0;
        }
        if (abastecimentos < P) {
            totalGas += 15;
            abastecimentos++;
        }
    }

    cout << "Finalmente cheguei, tive que abastecer em " << abastecimentos << " postos" << endl;
    return 0;
}
