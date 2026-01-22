/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    string numero;
    cin >> numero;
    if (numero[0] == numero[4] && numero[1] == numero[3]) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }
    return 0;
}
