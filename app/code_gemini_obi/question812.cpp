/*
Código criado pelo modelo gemini-2.5-pro
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, t = 1;
    while (cin >> N && N) {
        vector<int> saldo(N);
        for (int i = 0; i < N; ++i) {
            int x, y;
            cin >> x >> y;
            saldo[i] = x - y;
        }

        int max_sum = -1e9, cur_sum = 0, start = 0, ans_l = -1, ans_r = -1;
        int temp_l = 0;

        for (int i = 0; i < N; ++i) {
            cur_sum += saldo[i];
            if (cur_sum > max_sum || (cur_sum == max_sum && (i - temp_l > ans_r - ans_l))) {
                max_sum = cur_sum;
                ans_l = temp_l;
                ans_r = i;
            }
            if (cur_sum < 0) {
                cur_sum = 0;
                temp_l = i + 1;
            }
        }

        cout << "Teste " << t++ << endl;
        if (max_sum > 0)
            cout << ans_l + 1 << " " << ans_r + 1 << endl;
        else
            cout << "nenhum" << endl;
        cout << endl;
    }
    return 0;
}
