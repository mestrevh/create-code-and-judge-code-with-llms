/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int dia;
    cin >> dia;
    
    switch (dia) {
        case 1: cout << "Domingo"; break;
        case 2: cout << "Segunda"; break;
        case 3: cout << "Terca"; break;
        case 4: cout << "Quarta"; break;
        case 5: cout << "Quinta"; break;
        case 6: cout << "Sexta"; break;
        case 7: cout << "Sabado"; break;
        default: cout << "valor invalido"; break;
    }
    
    return 0;
}
