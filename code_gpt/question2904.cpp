/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    double C;
    int N;
    cin >> fixed >> setprecision(2) >> C >> N;

    vector<double> X(N);
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }

    double max_profit = 0.0;

    for (int i = 0; i < N; ++i) {
        double min_abs_change = X[i];
        for (int j = i + 1; j < N; ++j) {
            min_abs_change = min(min_abs_change, abs(X[j]));
            double profit = C * (min_abs_change / 100) * (j - i + 1);
            max_profit = max(max_profit, profit);
        }
    }

    cout << fixed << setprecision(2) << max_profit << endl;

    return 0;
}
