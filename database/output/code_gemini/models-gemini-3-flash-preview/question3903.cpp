/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    while (cin >> N >> K) {
        if (N <= 0) {
            continue;
        }

        vector<int> grades(N);
        for (int i = 0; i < N; ++i) {
            if (!(cin >> grades[i])) break;
        }

        if (K > N) K = N;
        if (K <= 0) {
            cout << 0 << "\n";
            continue;
        }

        nth_element(grades.begin(), grades.begin() + K - 1, grades.end(), greater<int>());

        long long sum_top_k = 0;
        for (int i = 0; i < K; ++i) {
            sum_top_k += grades[i];
        }

        cout << sum_top_k << "\n";
    }

    return 0;
}