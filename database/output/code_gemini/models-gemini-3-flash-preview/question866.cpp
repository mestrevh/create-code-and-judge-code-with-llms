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
    if (!(cin >> n)) return 0;
    if (n <= 0) return 0;

    vector<long long> arr(n);
    long long total_sum = 0;
    for (int j = 0; j < n; ++j) {
        if (!(cin >> arr[j])) break;
        total_sum += arr[j];
    }

    long long i, x;
    if (!(cin >> i >> x)) return 0;

    if (x <= 0) {
        cout << 0 << "\n";
        return 0;
    }

    long long k = x / n;
    long long r = x % n;

    long long result = k * total_sum;
    long long start_idx = i % n;

    for (long long j = 0; j < r; ++j) {
        result += arr[start_idx];
        start_idx = (start_idx + 1) % n;
    }

    cout << result << "\n";

    return 0;
}