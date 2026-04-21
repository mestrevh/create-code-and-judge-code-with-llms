/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n) || n <= 0) return 0;

    vector<long long> a(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    sort(a.begin(), a.end());

    double mean = (double)sum / n;

    double median;
    if (n % 2 != 0) {
        median = (double)a[n / 2];
    } else {
        median = (double)(a[n / 2 - 1] + a[n / 2]) / 2.0;
    }

    long long mode = a[0];
    int max_freq = 0;
    int current_freq = 0;
    for (int i = 0; i < n; ++i) {
        if (i > 0 && a[i] == a[i - 1]) {
            current_freq++;
        } else {
            current_freq = 1;
        }

        if (current_freq >= max_freq) {
            max_freq = current_freq;
            mode = a[i];
        }
    }

    cout << fixed << setprecision(2) << mean << " " << median << " " << (double)mode << endl;

    return 0;
}