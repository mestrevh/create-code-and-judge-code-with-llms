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

    double nota1, nota2;
    if (cin >> nota1 >> nota2) {
        const double peso1 = 6.0;
        const double peso2 = 4.0;
        double media = (nota1 * peso1 + nota2 * peso2) / (peso1 + peso2);
        
        cout << "Média= " << fixed << setprecision(1) << media << endl;
    }

    return 0;
}