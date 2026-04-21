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

    double mulheres, homens;
    if (!(cin >> mulheres >> homens)) return 0;

    double total = (mulheres * 10.0) + (homens * 8.5);
    double total_funcionarios = mulheres + homens;
    
    double media = 0.0;
    if (total_funcionarios > 0) {
        media = total / total_funcionarios;
    }

    cout << fixed << setprecision(2);
    cout << total << "\n";
    cout << media << "\n";

    return 0;
}