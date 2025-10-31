/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

struct cliente {
    int codigo;
    char nome[30];
    float credito;
};

void atualizarCliente(cliente &c) {
    cin >> c.codigo;
    cin >> c.nome;
    cin >> c.credito;
}

int main() {
    cliente c;
    atualizarCliente(c);
    cout << c.codigo << endl;
    cout << c.nome << endl;
    cout << fixed << setprecision(2) << c.credito << endl;
    return 0;
}
