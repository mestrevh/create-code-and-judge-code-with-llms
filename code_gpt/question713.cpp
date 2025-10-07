/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    bool hasMultiples = false;
    for (int i = A; i <= B; ++i) {
        if (i % N == 0) {
            cout << i << endl;
            hasMultiples = true;
        }
    }

    if (!hasMultiples) {
        cout << "INEXISTENTE" << endl;
    }

    return 0;
}
