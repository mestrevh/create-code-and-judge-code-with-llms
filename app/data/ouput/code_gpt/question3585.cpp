/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char tipo;
    cin >> tipo;
    
    if (tipo == 'a') {
        double n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        if (n1 < 1 || n1 > 10 || n2 < 1 || n2 > 10 || n3 < 1 || n3 > 10) {
            cout << "Notas erradas" << endl;
        } else {
            double media = (n1 + n2 + n3) / 3.0;
            cout << fixed << setprecision(2) << media << endl;
            if (media >= 7.0) cout << "Aprovado" << endl;
            else if (media <= 4.0) cout << "Reprovado" << endl;
            else cout << "Prova final" << endl;
        }
    } else if (tipo == 'p') {
        double n1, n2, n3, p1, p2, p3;
        cin >> n1 >> n2 >> n3 >> p1 >> p2 >> p3;
        if (n1 < 1 || n1 > 10 || n2 < 1 || n2 > 10 || n3 < 1 || n3 > 10) {
            cout << "Notas erradas" << endl;
        } else {
            double media = (n1 * p1 + n2 * p2 + n3 * p3) / (p1 + p2 + p3);
            cout << fixed << setprecision(2) << media << endl;
            if (media >= 7.0) cout << "Aprovado" << endl;
            else if (media <= 4.0) cout << "Reprovado" << endl;
            else cout << "Prova final" << endl;
        }
    } else if (tipo == 'h') {
        double n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        if (n1 < 1 || n1 > 10 || n2 < 1 || n2 > 10 || n3 < 1 || n3 > 10) {
            cout << "Notas erradas" << endl;
        } else {
            double media = 3.0 / ((1.0/n1) + (1.0/n2) + (1.0/n3));
            cout << fixed << setprecision(2) << media << endl;
            if (media >= 7.0) cout << "Aprovado" << endl;
            else if (media <= 4.0) cout << "Reprovado" << endl;
            else cout << "Prova final" << endl;
        }
    } else {
        cout << "Caractere invalido" << endl;
    }
    return 0;
}
