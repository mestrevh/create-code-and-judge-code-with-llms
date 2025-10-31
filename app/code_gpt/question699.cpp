/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int ano, periodicidade;
    cin >> ano >> periodicidade;

    for (int i = 1; i <= 3; i++) {
        cout << ano + i * periodicidade;
        if (i < 3) cout << " ";
    }
    cout << endl;
    return 0;
}
