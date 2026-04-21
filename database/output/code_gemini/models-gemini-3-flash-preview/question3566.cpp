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

    int n;
    if (cin >> n) {
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }

        for (int k = 2; k <= n; ++k) {
            if (n % k == 0) {
                cout << k << "\n";
                int s = n / k;
                for (int p = 0; p < k - 1; ++p) {
                    for (int j = 0; j < s; ++j) {
                        int idx1 = p * s + j;
                        int idx2 = (p + 2) * s - 1 - j;
                        cout << v[idx1] << " - " << v[idx2] << "\n";
                    }
                }
            }
        }
    }

    return 0;
}