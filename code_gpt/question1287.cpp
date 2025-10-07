/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int multiplicar(int A, int B) {
    if (B == 0) return 0;
    if (B < 0) return -multiplicar(A, -B);
    return A + multiplicar(A, B - 1);
}

int main() {
    int A, B;
    while (cin >> A >> B) {
        cout << multiplicar(A, B) << endl;
    }
    return 0;
}
