/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

void imprimirInverso() {
    int num;
    cin >> num;
    if (num != 0) {
        imprimirInverso();
        cout << num << endl;
    }
}

int main() {
    imprimirInverso();
    return 0;
}
