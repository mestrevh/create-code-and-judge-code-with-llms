/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int S, T, F;
    while (cin >> S >> T >> F) {
        int chegada = (S + T + F) % 24;
        cout << (chegada == 24 ? 0 : chegada) << endl;
    }
    return 0;
}
