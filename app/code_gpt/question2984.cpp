/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double nota1, nota2, nota3, frequencia;
    cin >> nota1 >> nota2 >> nota3 >> frequencia;

    double media = round((nota1 * 2 + nota2 * 2 + nota3 * 3) / 7 * 10) / 10;

    int frequencia_porcentagem = static_cast<int>(frequencia * 100);

    cout << "Frequencia: " << frequencia_porcentagem << "%" << endl;
    cout << "Media: " << fixed << setprecision(1) << media << endl;

    if (frequencia_porcentagem < 75) {
        cout << "Aluno reprovado por faltas!" << endl;
    } else if (media > 9) {
        cout << "Aluno aprovado com louvor!" << endl;
    } else if (media >= 6) {
        cout << "Aluno aprovado!" << endl;
    } else if (media >= 4) {
        cout << "Aluno de rec!" << endl;
    } else {
        cout << "Aluno reprovado!" << endl;
    }

    return 0;
}
