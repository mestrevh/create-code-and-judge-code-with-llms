/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int N, P, M, G;
    cin >> N >> P >> M >> G;

    if (!isPrime(N)) {
        cout << fixed << setprecision(2) << 0.00 << endl << 0.00 << endl;
        return 0;
    }

    double taxP = P * 25 * 0.125;
    double taxM = M * 40 * 0.29;
    double taxG = G * 70 * 0.22;

    double totalTax = taxP + taxM + taxG;
    double totalSales = (P * 25) + (M * 40) + (G * 70) + totalTax;

    cout << fixed << setprecision(2) << totalTax << endl;
    cout << totalSales << endl;

    return 0;
}
