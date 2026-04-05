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

    double n1, n2, n3;
    while (cin >> n1 >> n2 >> n3) {
        cout << "Informe a primeira nota:" << "\n";
        cout << "Informe a segunda nota:" << "\n";
        cout << "Informe a terceira nota:" << "\n";

        double avg = (n1 + n2 + n3) / 3.0;

        cout << fixed << setprecision(1);
        if (avg >= 7.0) {
            cout << "Aprovado com media " << avg << "\n";
        } else if (avg >= 5.0) {
            // A nota deve ser impressa com uma casa decimal conforme a instrução literal.
            // O caso de teste 1 (5.666...7) parece contradizer essa regra específica,
            // mas em programação competitiva, regras textuais explícitas geralmente
            // prevalecem sobre exemplos possivelmente não formatados.
            cout << "Recuperacao com media " << avg << "\n";
        } else {
            cout << "Reprovado com media " << avg << "\n";
        }
    }

    return 0;
}