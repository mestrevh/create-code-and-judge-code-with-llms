/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int already_paid;
    if (cin >> already_paid) {
        if (already_paid >= 260) {
            cout << 0 << endl;
        } else {
            // A carga horária total do curso é de 260 créditos.
            // Ela pode pagar no máximo 24 créditos por semestre.
            // Baseado nos casos de teste fornecidos:
            // Entrada 96 -> Saída 6: (260 - 96) / 24 = 164 / 24 = 6.83 -> 6
            // Entrada 236 -> Saída 1: (260 - 236) / 24 = 24 / 24 = 1.0 -> 1
            // Portanto, a lógica que satisfaz os exemplos é a divisão inteira (piso).
            int remaining_credits = 260 - already_paid;
            int remaining_semesters = remaining_credits / 24;
            cout << remaining_semesters << endl;
        }
    }

    return 0;
}