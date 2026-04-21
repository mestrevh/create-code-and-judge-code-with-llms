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

    long long trucks = 0;
    long long totalCost = 0;
    long long maxDays = 0;

    for (int i = 0; i < N; i++) {
        long long T, E, dist;
        cin >> T >> E >> dist;

        long long capacity = (E == 1) ? 5 : 10;
        long long price = (E == 1) ? 1200 : 500;

        long long need = (T + capacity - 1) / capacity;
        long long days = (dist + ((E == 1) ? 250LL : 100LL) - 1) / ((E == 1) ? 250LL : 100LL);

        trucks += need;
        totalCost += need * price;
        maxDays = max(maxDays, days);
    }

    cout << trucks << " " << totalCost << " " << maxDays << "\n";
    return 0;
}