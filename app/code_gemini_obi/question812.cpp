/*
Código criado pelo modelo gemini-2.5-pro
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, test = 1;
    while (cin >> N, N != 0) {
        vector<int> saldo(N);
        for (int i = 0; i < N; ++i) {
            int x, y;
            cin >> x >> y;
            saldo[i] = x - y;
        }
        int max_sum = -1e9, curr_sum = 0, start = 0, best_start = 0, best_end = 0, max_len = -1;
        for (int i = 0; i < N; ++i) {
            if (curr_sum < 0) {
                curr_sum = saldo[i];
                start = i;
            } else {
                curr_sum += saldo[i];
            }
            int len = i - start;
            if ((curr_sum > max_sum) || (curr_sum == max_sum && len > max_len)) {
                max_sum = curr_sum;
                max_len = len;
                best_start = start;
                best_end = i;
            }
        }
        cout << "Teste " << test++ << "\n";
        if (max_sum > 0)
            cout << best_start + 1 << " " << best_end + 1 << "\n";
        else
            cout << "nenhum\n";
        cout << "\n";
    }
    return 0;
}
