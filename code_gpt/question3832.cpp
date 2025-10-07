/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    if (N < M) {
        cout << "Pedro vai ter que fugir" << endl;
    } else {
        cout << "Esta pago" << endl;
        int sobra = N - M;
        if (sobra > 0) {
            cout << "Sobrou " << sobra << endl;
        }
        if (sobra > 0 && M < N) {
            cout << "Pegou mais" << endl;
        }
    }
    return 0;
}
