/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    if (!(cin >> N)) return 0;

    vector<int> digits;
    digits.reserve(1000000);
    digits.push_back(1);

    for (long long i = 0; i < N; i++) {
        int carry = 0;
        for (size_t j = 0; j < digits.size(); j++) {
            long long val = 2LL * digits[j] + carry;
            digits[j] = (int)(val % 10);
            carry = (int)(val / 10);
        }
        while (carry) {
            digits.push_back(carry % 10);
            carry /= 10;
        }
    }

    if (digits.empty()) digits.push_back(0);

    int start = (int)digits.size() - 1;
    bool first = true;
    for (int i = start; i >= 0; ) {
        int cnt = min(50, i + 1);
        if (!first) cout << "\n";
        first = false;
        int l = i - cnt + 1;
        for (int k = i; k >= l; k--) cout << digits[k];
        i = l - 1;
    }
    cout << "\n";
    return 0;
}