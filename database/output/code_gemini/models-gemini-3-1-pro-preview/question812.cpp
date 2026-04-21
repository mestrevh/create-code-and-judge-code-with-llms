/*
Código criado pelo models/gemini-3.1-pro-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int test_case = 1;

    while (cin >> n && n != 0) {
        int max_sum = 0;
        int current_sum = 0;
        int current_start = 1;
        int best_start = -1;
        int best_end = -1;

        for (int i = 1; i <= n; ++i) {
            int x, y;
            cin >> x >> y;
            int diff = x - y;

            current_sum += diff;

            if (current_sum < 0) {
                current_sum = 0;
                current_start = i + 1;
            } else if (current_sum > 0) {
                if (current_sum > max_sum || (current_sum == max_sum && (i - current_start + 1) > (best_end - best_start + 1))) {
                    max_sum = current_sum;
                    best_start = current_start;
                    best_end = i;
                }
            }
        }

        cout << "Teste " << test_case++ << "\n";
        if (max_sum > 0) {
            cout << best_start << " " << best_end << "\n\n";
        } else {
            cout << "nenhum\n\n";
        }
    }

    return 0;
}