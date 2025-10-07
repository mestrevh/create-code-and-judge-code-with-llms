/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int notas50 = n / 50;
    n %= 50;
    int notas20 = n / 20;
    n %= 20;
    int notas10 = n / 10;
    n %= 10;
    int notas5 = n / 5;
    n %= 5;
    int notas1 = n;

    cout << "Notas de 50: " << notas50 << endl;
    cout << "Notas de 20: " << notas20 << endl;
    cout << "Notas de 10: " << notas10 << endl;
    cout << "Notas de 5: " << notas5 << endl;
    cout << "Notas de 1: " << notas1 << endl;

    return 0;
}
