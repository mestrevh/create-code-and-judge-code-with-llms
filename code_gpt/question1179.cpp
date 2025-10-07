/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int L;
    cin >> L;
    int P;

    if (L >= 1 && L <= 20) {
        P = 20 + (L * L * L);
    } else if (L >= 21 && L <= 40) {
        P = 8000 + ((L - 10) * (L - 10));
    } else if (L >= 41 && L <= 60) {
        P = 9000 + (5 * L);
    } else if (L >= 61 && L <= 80) {
        P = 9300 + (2 * L);
    } else {
        P = 9500 + L;
    }

    cout << "Potencia de : " << P << " W" << endl;
    return 0;
}
