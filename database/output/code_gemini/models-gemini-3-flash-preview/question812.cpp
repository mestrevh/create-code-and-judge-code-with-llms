/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, teste = 1;
    while (cin >> n && n != 0) {
        int max_saldo = 0;
        int best_a = -1, best_b = -1;
        int current_sum = 0;
        int current_start = 1;

        for (int i = 1; i <= n; ++i) {
            int x, y;
            cin >> x >> y;
            int diff = x - y;
            current_sum += diff;

            if (current_sum < 0) {
                current_sum = 0;
                current_start = i + 1;
            } else if (current_sum > 0) {
                if (current_sum > max_saldo) {
                    max_saldo = current_sum;
                    best_a = current_start;
                    best_b = i;
                } else if (current_sum == max_saldo) {
                    // Tie-breaker: choose the longest period (B - A is greater)
                    if (i - current_start >= best_b - best_a) {
                        best_a = current_start;
                        best_b = i;
                    }
                }
            }
        }

        cout << "Teste " << teste++ << "\n";
        if (max_saldo > 0) {
            cout << best_a << " " << best_b << "\n\n";
        } else {
            cout << "nenhum\n\n";
        }
    }

    return 0;
}