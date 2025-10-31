/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double nota1, nota2, nota3;
    cin >> nota1 >> nota2 >> nota3;

    double media = (nota1 + nota2 + nota3) / 3.0;
    double mediaPonderada1 = (nota1 * 2 + nota2 * 2 + nota3 * 3) / 7.0;
    double mediaPonderada2 = (nota1 * 1 + nota2 * 2 + nota3 * 2) / 5.0;

    cout << fixed << setprecision(2);
    cout << media << endl;
    cout << mediaPonderada1 << endl;
    cout << mediaPonderada2 << endl;

    return 0;
}
