/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

bool ehBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int main() {
    int ano;
    cin >> ano;
    if (ehBissexto(ano))
        cout << "eh bissexto" << endl;
    else
        cout << "nao eh bissexto" << endl;
    return 0;
}
