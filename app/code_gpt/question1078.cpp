/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    if (n1 < 0 || n2 < 0 || n3 < 0 || n1 > 100 || n2 > 100 || n3 > 100) {
        cout << "Media invalida" << endl;
        return 0;
    }

    double media = (n1 + n2 + n3) / 3.0;
    string situacao;

    if (media >= 70 && media <= 100) {
        situacao = "APROVADO";
    } else if (media >= 0 && media <= 40) {
        situacao = "REPROVADO";
    } else if (media > 40 && media < 70) {
        situacao = "FINAL";
    }

    cout << fixed << setprecision(2) << "A media do aluno foi " << media << " e ele foi " << situacao << endl;

    return 0;
}
