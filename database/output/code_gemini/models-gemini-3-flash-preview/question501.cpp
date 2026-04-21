/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string tipo;
    double valor;
    int exames_cont = 0;
    int consultas_cont = 0;
    double total_desembolsado = 0.0;

    for (int i = 0; i < 8; ++i) {
        if (!(cin >> tipo >> valor)) break;

        if (tipo == "exame") {
            exames_cont++;
            if (exames_cont > 2) {
                total_desembolsado += valor * 0.60;
            }
        } else if (tipo == "consulta") {
            consultas_cont++;
            if (consultas_cont > 3) {
                total_desembolsado += valor * 0.30;
            }
        }
    }

    cout << fixed << setprecision(2) << total_desembolsado << endl;

    return 0;
}