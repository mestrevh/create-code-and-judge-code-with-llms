/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double preco;
    char categoria_input;

    if (!(cin >> preco >> categoria_input)) {
        return 0;
    }

    char c = (char)tolower(static_cast<unsigned char>(categoria_input));
    string categoria_nome;
    double fator_preco = 1.0;
    bool valida = true;

    if (c == 'e') {
        categoria_nome = "Estudante";
        fator_preco = 0.5;
    } else if (c == 'a') {
        categoria_nome = "Aposentado";
        fator_preco = 0.7;
    } else if (c == 'n') {
        categoria_nome = "Normal";
        fator_preco = 1.0;
    } else {
        valida = false;
    }

    if (!valida) {
        cout << "Categoria inválida" << endl;
    } else {
        cout << fixed << setprecision(2);
        cout << "Preco com desconto: R$" << preco * fator_preco << "\n";
        cout << "Categoria: " << categoria_nome << endl;
    }

    return 0;
}