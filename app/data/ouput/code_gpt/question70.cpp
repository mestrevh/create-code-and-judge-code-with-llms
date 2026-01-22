/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

double factorial(int n) {
    double result = 1.0;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int x, n;
    while (cin >> x >> n) {
        if (x == 0 && n == 0) break;
        double sum = 0.0;
        for (int i = 0; i < n; ++i) {
            sum += (pow(x, i) / factorial(i));
        }
        cout << fixed << setprecision(6) << sum << endl;
    }
    return 0;
}
