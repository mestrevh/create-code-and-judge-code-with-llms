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
    
    long long bestSum = -1;
    int bestIdx = 1;
    
    for (int i = 1; i <= N; i++) {
        long long sum = 0;
        for (int j = 0; j < M; j++) {
            long long x;
            cin >> x;
            sum += x;
        }
        if (bestSum == -1 || sum < bestSum) {
            bestSum = sum;
            bestIdx = i;
        }
    }
    
    cout << bestIdx << "\n";
    return 0;
}