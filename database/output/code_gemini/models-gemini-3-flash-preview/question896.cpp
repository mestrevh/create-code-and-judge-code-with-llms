/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double nota;
    cout << "Informe uma nota entre 0 e 10:\n";
    
    while (cin >> nota) {
        if (nota >= 0 && nota <= 10) {
            break;
        }
        cout << "Valor invalido\n";
        cout << "Informe uma nota entre 0 e 10:\n";
    }

    return 0;
}