/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char type;
    if (!(cin >> type)) return 0;

    if (type != 'a' && type != 'p' && type != 'h') {
        cout << "Caractere invalido" << endl;
        return 0;
    }

    double n1, n2, n3;
    if (!(cin >> n1 >> n2 >> n3)) return 0;

    if (n1 > 10.0 || n2 > 10.0 || n3 > 10.0) {
        cout << "Notas erradas" << endl;
        return 0;
    }

    double avg = 0;
    if (type == 'a') {
        avg = (n1 + n2 + n3) / 3.0;
    } else if (type == 'p') {
        double w1, w2, w3;
        if (!(cin >> w1 >> w2 >> w3)) return 0;
        avg = (n1 * w1 + n2 * w2 + n3 * w3) / (w1 + w2 + w3);
    } else if (type == 'h') {
        if (n1 == 0 || n2 == 0 || n3 == 0) {
            avg = 0;
        } else {
            avg = 3.0 / ((1.0 / n1) + (1.0 / n2) + (1.0 / n3));
        }
    }

    if (avg < 0.0 || avg > 10.0000001) {
        cout << "Notas erradas" << endl;
    } else {
        cout << fixed << setprecision(2) << avg << endl;
        if (avg >= 7.0) {
            cout << "Aprovado" << endl;
        } else if (avg >= 0.0 && avg <= 4.0) {
            cout << "Reprovado" << endl;
        } else {
            cout << "Prova final" << endl;
        }
    }

    return 0;
}