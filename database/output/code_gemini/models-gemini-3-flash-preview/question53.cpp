/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long double s = 0.0L;
    long long n_count = 0;
    long long answers[16];

    for (int k = 0; k <= 15; ++k) {
        while (s <= (long double)k) {
            n_count++;
            s += 1.0L / (long double)n_count;
        }
        answers[k] = n_count;
    }

    int k_val;
    while (cin >> k_val && k_val != -1) {
        if (k_val >= 0 && k_val <= 15) {
            cout << answers[k_val] << "\n";
        } else if (k_val < -1) {
            cout << 1 << "\n";
        }
    }

    return 0;
}