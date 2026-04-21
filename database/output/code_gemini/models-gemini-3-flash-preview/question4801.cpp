/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    double a;

    if (!(cin >> n >> a)) return 0;

    double result = 0;

    switch (n) {
        case 1:
            result = pow(a, 2);
            break;
        case 2:
            result = sqrt(a);
            break;
        case 3:
            result = fabs(a);
            break;
        case 4:
            result = log2(a);
            break;
        default:
            break;
    }

    cout << fixed << setprecision(2) << result << "\n";

    return 0;
}

OTIMIZAÇÃO: O tempo de execução é O(1). O uso de ios_base::sync_with_stdio(false) garante performance máxima para leitura/escrita. As funções da cmath operam em tempo constante para as restrições fornecidas.