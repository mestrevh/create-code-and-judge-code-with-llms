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

    int m, n;
    if (!(cin >> m >> n)) {
        return 0;
    }

    vector<int> sequence(m);
    for (int i = 0; i < m; ++i) {
        cin >> sequence[i];
    }

    for (int pass = 1; pass <= n; ++pass) {
        for (int j = 0; j < m - pass; ++j) {
            if (sequence[j] > sequence[j + 1]) {
                int temp = sequence[j];
                sequence[j] = sequence[j + 1];
                sequence[j + 1] = temp;
            }
        }

        cout << "[";
        for (int k = 0; k < m; ++k) {
            cout << sequence[k];
            if (k < m - 1) {
                cout << ", ";
            }
        }
        cout << "]\n";
    }

    return 0;
}