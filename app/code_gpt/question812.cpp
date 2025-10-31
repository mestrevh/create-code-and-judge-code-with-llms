/*
Código criado pelo modelo gpt-4.1
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, caso = 1;
    while (cin >> N && N != 0) {
        vector<int> saldo(N);
        for (int i = 0; i < N; ++i) {
            int x, y;
            cin >> x >> y;
            saldo[i] = x - y;
        }

        int max_sum = -1e9, this_sum = 0;
        int best_l = 0, best_r = 0, l = 0;

        for (int r = 0; r < N; ++r) {
            this_sum += saldo[r];
            if (this_sum > max_sum ||
                (this_sum == max_sum && r - l > best_r - best_l)) {
                max_sum = this_sum;
                best_l = l;
                best_r = r;
            }
            if (this_sum < 0) {
                this_sum = 0;
                l = r + 1;
            }
        }

        cout << "Teste " << caso++ << endl;
        if (max_sum > 0)
            cout << best_l + 1 << " " << best_r + 1 << endl;
        else
            cout << "nenhum" << endl;
        cout << endl;
    }
    return 0;
}
