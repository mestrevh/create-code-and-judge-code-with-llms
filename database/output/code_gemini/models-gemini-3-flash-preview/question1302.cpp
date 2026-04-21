/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long sum_positive = 0;
    int count_positive = 0;
    long long min_val = numeric_limits<long long>::max();
    long long sum_non_diag = 0;
    long long val;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (!(cin >> val)) break;

            if (val > 0) {
                sum_positive += val;
                count_positive++;
            }

            if (val < min_val) {
                min_val = val;
            }

            if (i != j) {
                sum_non_diag += val;
            }
        }
    }

    double avg_positive = 0.0;
    if (count_positive > 0) {
        avg_positive = static_cast<double>(sum_positive) / count_positive;
    }

    int delta = (min_val % 2 == 0) ? 1 : 0;

    cout << fixed << setprecision(2) << avg_positive << " " << min_val << " " << delta << " " << sum_non_diag << endl;

    return 0;
}