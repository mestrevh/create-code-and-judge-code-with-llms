/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long A, B, C, D;
    if (!(cin >> A >> B >> C >> D)) return 0;

    if (C % A != 0) {
        cout << -1 << endl;
        return 0;
    }

    vector<long long> divisors;
    for (long long i = 1; i * i <= C; ++i) {
        if (C % i == 0) {
            divisors.push_back(i);
            if (i * i != C) {
                divisors.push_back(C / i);
            }
        }
    }

    sort(divisors.begin(), divisors.end());

    long long result = -1;
    for (long long n : divisors) {
        if (n % A == 0 && n % B != 0 && D % n != 0) {
            result = n;
            break;
        }
    }

    cout << result << endl;

    return 0;
}