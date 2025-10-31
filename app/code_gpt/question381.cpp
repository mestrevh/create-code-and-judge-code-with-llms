/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    double peso, total = 0;
    int cont = 0;
    
    while (true) {
        cin >> peso;
        if (total + peso > 18) break;
        total += peso;
        cont++;
    }
    
    cout << cont << endl;
    return 0;
}
