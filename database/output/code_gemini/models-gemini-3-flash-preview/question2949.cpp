/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int C;
    if (!(cin >> C)) return 0;

    for (int t = 1; t <= C; ++t) {
        int N;
        if (!(cin >> N)) break;

        vector<int> a(N);
        double sum = 0;
        int counts[201];
        for (int i = 0; i < 201; ++i) counts[i] = 0;

        for (int i = 0; i < N; ++i) {
            cin >> a[i];
            sum += a[i];
            counts[a[i] + 100]++;
        }

        sort(a.begin(), a.end());

        cout << "sequencia " << t << ":\n";
        for (int i = 0; i < N; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";

        cout << a[0] << " " << a[N - 1] << "\n";

        cout << sum / (double)N << "\n";

        int max_f = 0;
        for (int i = 0; i < 201; ++i) {
            if (counts[i] > max_f) {
                max_f = counts[i];
            }
        }

        if (max_f > 1) {
            for (int i = 0; i < 201; ++i) {
                if (counts[i] == max_f) {
                    cout << i - 100 << " ";
                }
            }
        }
        cout << "\n";

        double median;
        if (N % 2 != 0) {
            median = (double)a[N / 2];
        } else {
            median = (double)(a[N / 2 - 1] + a[N / 2]) / 2.0;
        }
        cout << median << "\n";
    }

    return 0;
}