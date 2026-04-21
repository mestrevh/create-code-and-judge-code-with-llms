/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    vector<long long> a(N + 1);
    for (int i = 1; i <= N; i++) cin >> a[i];

    long long bestSum = -1;
    int bestL = 1, bestR = 2;

    long long curSum = 0;
    int curL = 1;

    for (int i = 1; i <= N; i++) {
        if (i == 1) {
            curL = 1;
            curSum = a[1];
            continue;
        }
        if (a[i] > a[i - 1]) {
            curSum += a[i];
        } else {
            if (curSum > bestSum) {
                bestSum = curSum;
                bestL = curL;
                bestR = i - 1;
            }
            curL = i;
            curSum = a[i];
        }
    }

    if (curSum > bestSum) {
        bestSum = curSum;
        bestL = curL;
        bestR = N;
    }

    cout << bestL << " " << bestR << " " << bestSum << "\n";
    return 0;
}