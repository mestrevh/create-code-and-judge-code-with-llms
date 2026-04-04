/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double price = 5.0;
    int publico = 120;
    const double fixed_expenses = 200.0;

    for (int i = 0; i < 9; ++i) {
        double current_price = price - (i * 0.5);
        int current_publico = publico + (i * 26);
        double lucro = (current_price * current_publico) - fixed_expenses;

        cout << "preco do ingresso: R$ " << current_price 
             << " / publico esperado: " << current_publico 
             << " / lucro esperado: R$ " << lucro << "\n";
    }

    return 0;
}