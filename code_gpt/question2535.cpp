/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int u;
    cout << "Digite um numero:" << endl;
    cin >> u;
    
    if (u > 0) {
        cout << "O numero e positivo" << endl;
    } else if (u < 0) {
        cout << "O numero e negativo" << endl;
    } else {
        cout << "O numero e nulo" << endl;
    }
    
    return 0;
}
