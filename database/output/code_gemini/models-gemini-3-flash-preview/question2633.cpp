/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char estudante, idoso;

    cout << "Cliente e estudante? (s ou n)" << endl;
    if (!(cin >> estudante)) return 0;
    
    cout << "Cliente e idoso? (s ou n)" << endl;
    if (!(cin >> idoso)) return 0;

    auto is_valid = [](char c) {
        return c == 's' || c == 'S' || c == 'n' || c == 'N';
    };

    auto is_yes = [](char c) {
        return c == 's' || c == 'S';
    };

    if (!is_valid(estudante) || !is_valid(idoso)) {
        cout << "Entrada deve ser apenas pelas letras s ou n." << endl;
    } else {
        if (is_yes(estudante) || is_yes(idoso)) {
            cout << "Meia-entrada. Valor a ser pago: R$10,00." << endl;
        } else {
            cout << "Entrada completa. Valor a ser pago: R$20,00." << endl;
        }
    }

    return 0;
}