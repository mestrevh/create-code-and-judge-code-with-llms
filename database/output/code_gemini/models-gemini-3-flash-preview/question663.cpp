/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int B, N;
    while (cin >> B >> N && (B != 0 || N != 0)) {
        vector<int> reserves(B + 1);
        for (int i = 1; i <= B; ++i) {
            cin >> reserves[i];
        }

        for (int i = 0; i < N; ++i) {
            int debtor, creditor, value;
            cin >> debtor >> creditor >> value;
            reserves[debtor] -= value;
            reserves[creditor] += value;
        }

        bool all_positive = true;
        for (int i = 1; i <= B; ++i) {
            if (reserves[i] < 0) {
                all_positive = false;
                break;
            }
        }

        if (all_positive) {
            cout << 'S' << "\n";
        } else {
            cout << 'N' << "\n";
        }
    }

    return 0;
}