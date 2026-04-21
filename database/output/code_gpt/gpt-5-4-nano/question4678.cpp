/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    if (!(0 < N && N <= 10 && 0 < M && M <= 10)) {
        cout << "Han??";
        return 0;
    }

    int totalCells = N * M;
    vector<long long> rowSums(N, 0);

    for (int i = 0; i < N; i++) {
        long long sum = 0;
        for (int j = 0; j < M; j++) {
            long long x;
            cin >> x;
            sum += x;
        }
        rowSums[i] = sum;
    }

    long long maxSum = 0;
    for (auto s : rowSums) maxSum = max(maxSum, s);

    auto isPrime = [&](long long x) -> bool {
        if (x < 2) return false;
        if (x % 2 == 0) return x == 2;
        for (long long d = 3; d * d <= x; d += 2) {
            if (x % d == 0) return false;
        }
        return true;
    };

    int primeCount = 0;
    for (auto s : rowSums) {
        if (isPrime(s)) primeCount++;
    }

    if (primeCount > N / 2) cout << "Chama";
    else cout << "Não chama";

    return 0;
}