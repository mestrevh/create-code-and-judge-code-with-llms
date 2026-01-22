/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int D, R, L, P, G;
    cin >> D >> R >> L >> P >> G;

    int gasolinaNecessaria = D / 10;
    int litrosParaAbastecer = max(0, gasolinaNecessaria - L);
    int custoAbastecimento = litrosParaAbastecer * G;

    if (custoAbastecimento <= R) {
        cout << "Pode viajar.\nR$: " << R - custoAbastecimento << endl;
    } else {
        cout << "Nao pode viajar." << endl;
    }

    return 0;
}
