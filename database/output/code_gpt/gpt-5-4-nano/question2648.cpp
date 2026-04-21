/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

using Big = boost::multiprecision::cpp_int;

Big parseReversedDigits(int N, const vector<int>& digits, int idx = 0) {
    if (idx == N) return 0;
    Big digit = digits[idx];
    return digit * 1 + 10 * parseReversedDigits(N, digits, idx + 1);
}

Big buildNumber(int N, const vector<int>& digits) {
    Big val = 0;
    Big pow10 = 1;
    for (int i = 0; i < N; i++) {
        val += Big(digits[i]) * pow10;
        pow10 *= 10;
    }
    return val;
}

Big sumAll(int p, int i, const vector<pair<int, vector<int>>>& parts) {
    if (i == p) return 0;
    return buildNumber(parts[i].first, parts[i].second) + sumAll(p, i + 1, parts);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int P;
    if (!(cin >> P)) return 0;
    vector<pair<int, vector<int>>> parts;
    parts.reserve(P);

    for (int i = 0; i < P; i++) {
        int N;
        cin >> N;
        vector<int> digits(N);
        for (int j = 0; j < N; j++) cin >> digits[j];
        parts.push_back({N, digits});
    }

    Big result = sumAll(P, 0, parts);
    cout << result;
    return 0;
}