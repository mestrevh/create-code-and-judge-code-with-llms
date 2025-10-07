/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int negativos = 0;
    double a;
    
    for (int i = 0; i < 5; i++) {
        cout << "Digite um valor:" << endl;
        cin >> a;
        if (a < 0) negativos++;
    }
    
    cout << "Foram digitados " << negativos << " numeros negativos" << endl;
    return 0;
}
