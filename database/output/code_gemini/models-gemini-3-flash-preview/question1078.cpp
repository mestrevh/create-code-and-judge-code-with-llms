/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double n1, n2, n3;
    if (!(cin >> n1 >> n2 >> n3)) return 0;

    double media = (n1 + n2 + n3) / 3.0;

    if (media < 0.0 || media > 100.0) {
        cout << "Media invalida" << endl;
    } else {
        cout << "A media do aluno foi " << fixed << setprecision(2) << media << " e ele foi ";
        if (media >= 70.0 && media <= 100.0) {
            cout << "APROVADO" << endl;
        } else if (media >= 0.0 && media <= 40.0) {
            cout << "REPROVADO" << endl;
        } else {
            cout << "FINAL" << endl;
        }
    }

    return 0;
}