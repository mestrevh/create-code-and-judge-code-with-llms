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

    double n1, n2;
    int operacao;

    if (!(cin >> n1 >> n2 >> operacao)) return 0;

    double resultado = 0.0;

    switch (operacao) {
        case 1:
            resultado = n1 + n2;
            break;
        case 2:
            resultado = n1 - n2;
            break;
        case 3:
            resultado = n1 * n2;
            break;
        case 4:
            if (n2 != 0) {
                resultado = n1 / n2;
            } else {
                resultado = 0.0; 
            }
            break;
        default:
            return 0;
    }

    cout << fixed << setprecision(3) << resultado << endl;

    return 0;
}