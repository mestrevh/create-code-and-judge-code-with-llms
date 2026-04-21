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

    double altura;
    if (cin >> altura) {
        double peso_ideal = (72.7 * altura) - 58.0;

        cout << "Informe sua altura:" << "\n";
        cout << "Peso ideal: " << setprecision(16) << peso_ideal << endl;
    }

    return 0;
}