/*
Código criado pelo modelo gemini-2.5-pro
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int L, C;
    cin >> L >> C;

    int tipo1 = 0, tipo2 = 0;
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            // Para cada "quadrado unitário", conta quantas lajotas do tipo 1 têm o centro dentro do retângulo
            // Se (i+j) % 2 == 0, centro desse quadrado é coberto por uma lajota tipo 1
            if ((i + j) % 2 == 0) tipo1++;
            else tipo2++;
        }
    }
    tipo2 *= 2;

    cout << tipo1 << endl;
    cout << tipo2 << endl;

    return 0;
}
