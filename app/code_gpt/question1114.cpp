/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

double calculateSeries(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        int numerator = i % 2 == 1 ? i : (1 << (i / 2)); // 2^(i/2) for even i
        int denominator = (i + 2) / 3 + 2; // 2, 3, 4 for i = 1, 2, 3,...
        sum += static_cast<double>(numerator) / denominator;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    double result = calculateSeries(n);
    cout << fixed << setprecision(2) << "S: " << result << endl;
    return 0;
}
