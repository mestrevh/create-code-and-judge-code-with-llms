/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int N, A, B, soma = 0;
    cin >> N >> A >> B;

    for (int i = 1; i <= N; ++i) {
        if (i % A != 0 && i % B != 0) {
            soma += i;
        }
    }

    cout << soma << endl;
    return 0;
}
