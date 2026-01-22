/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

void eh_bissexto(int ano) {
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        cout << "bissexto" << endl;
    } else {
        cout << "nao bissexto" << endl;
    }
}

int main() {
    int ano;
    cin >> ano;
    eh_bissexto(ano);
    return 0;
}
