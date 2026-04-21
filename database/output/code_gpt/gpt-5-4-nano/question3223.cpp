/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    if (!(cin >> N >> K)) return 0;

    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];

    long long sum = 0;
    for (int i = 0; i < K; i++) sum += H[i];

    long long bestSum = sum;
    int bestJ = 1;

    for (int i = K; i < N; i++) {
        sum += H[i] - H[i - K];
        if (sum < bestSum) {
            bestSum = sum;
            bestJ = i - K + 2;
        }
    }

    cout << bestJ << "\n";
    return 0;
}