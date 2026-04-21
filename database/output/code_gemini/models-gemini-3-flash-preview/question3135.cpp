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

    long long n;
    if (!(cin >> n)) {
        return 0;
    }

    if (n <= 0) {
        if (n == 0) {
            cout << 0 << "\n";
        }
        return 0;
    }

    vector<long long> divs;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divs.push_back(i);
            if (i * i != n) {
                divs.push_back(n / i);
            }
        }
    }
    sort(divs.begin(), divs.end());

    long long min_a = -1;
    int sz = (int)divs.size();

    for (int i = 0; i < sz; ++i) {
        long long a = divs[i];
        if (a * a * a > n) {
            break;
        }

        long long m = n / a;
        for (int j = i; j < sz; ++j) {
            long long b = divs[j];
            if (b * b > m) {
                break;
            }

            if (m % b == 0) {
                long long c = m / b;
                long long cur = 2 * (a * b + b * c + c * a);
                if (min_a == -1 || cur < min_a) {
                    min_a = cur;
                }
            }
        }
    }

    cout << min_a << "\n";

    return 0;
}