/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double broas, paes;
    while (cin >> broas >> paes) {
        double total_broas = broas * 1.50;
        double total_paes = paes * 0.20;
        double total_arrecadado = total_broas + total_paes;
        double poupanca = total_arrecadado * 0.10;

        cout << "O valor a ser guardado na poupança será R$ " 
             << fixed << setprecision(2) << poupanca << "\n";
    }

    return 0;
}