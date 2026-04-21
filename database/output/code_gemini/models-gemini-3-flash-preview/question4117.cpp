/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int max_C;
    if (!(cin >> max_C)) {
        return 0;
    }

    int current_A = 0;
    int current_C = 0;

    int join_A, join_R, join_G;
    while (cin >> join_A && join_A >= 0) {
        if (!(cin >> join_R >> join_G)) {
            break;
        }

        int join_total_C = join_R + join_G;

        if (join_total_C == 0) {
            current_A += join_A;
            cout << "Acesso permitido!" << "\n";
        } else if (current_C + join_total_C <= max_C) {
            current_A += join_A;
            current_C += join_total_C;
            cout << "Acesso permitido!" << "\n";
        } else if (join_G > 0) {
            current_A += join_A;
            current_C += join_total_C;
            cout << "Acesso permitido devido a presenca de convidado(s)." << "\n";
        } else {
            cout << "Capacidade maxima de criancas atingida/excedida." << "\n";
            int excess = current_C - max_C;
            if (excess < 0) excess = 0;
            cout << "Tem " << excess << " crianca(s) a mais que as " << max_C << " permitidas." << "\n";
        }

        cout << "Adultos na piscina: " << current_A << "\n";
        cout << "Criancas na piscina: " << current_C << "\n";
        cout << "***" << endl;
    }

    return 0;
}