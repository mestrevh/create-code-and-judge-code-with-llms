/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<double> grades(N);
    for (int i = 0; i < N; ++i) {
        cin >> grades[i];
    }

    double sum_weighted = 0.0;
    double sum_weights = 0.0;
    for (int i = 0; i < N; ++i) {
        double p;
        cin >> p;
        sum_weighted += (grades[i] * p);
        sum_weights += p;
    }

    if (sum_weights == 0) {
        cout << fixed << setprecision(2) << 0.00 << endl;
    } else {
        cout << fixed << setprecision(2) << (sum_weighted / sum_weights) << endl;
    }

    return 0;
}