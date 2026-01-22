/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double calc(int n) {
    double sum = 0.0;
    for (int i = 0; i <= n; ++i) {
        sum += sin(i) + cos(i);
    }
    return sum;
}

int main() {
    int n, m;
    cin >> n >> m;

    double total = 0.0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            total += calc(i + j);
        }
    }

    cout << fixed << setprecision(6) << total << endl;
    return 0;
}
