/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;

    if (N == 0) {
        cout << "NULO" << endl;
    } else if (N > 0) {
        cout << (N % 2 == 0 ? "POSITIVO PAR" : "POSITIVO IMPAR") << endl;
    } else {
        cout << (N % 2 == 0 ? "NEGATIVO PAR" : "NEGATIVO IMPAR") << endl;
    }

    return 0;
}
