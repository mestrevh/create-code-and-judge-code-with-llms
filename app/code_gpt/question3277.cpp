/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int nota;
    cin >> nota;
    if (nota >= 0 && nota <= 10) {
        cout << "valida" << endl;
    } else {
        cout << "invalida" << endl;
    }
    return 0;
}
