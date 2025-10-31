/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <limits>

using namespace std;

struct Store {
    long long power;
    long long cost;
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<long long> energy(N);
    for (int i = 0; i < N; ++i) {
        cin >> energy[i];
    }

    vector<vector<Store>> shops(N);
    for (int i = 0; i < M; ++i) {
        int L;
        long long S, C;
        cin >> L >> S >> C;
        shops[L - 1].push_back({S, C});
    }

    long long totalCost = 0;
    long long currentEnergy = 0;

    for (int i = 0; i < N; ++i) {
        if (currentEnergy < energy[i]) {
            long long needed = energy[i] - currentEnergy;
            long long minCost = LLONG_MAX;
            for (const auto &shop : shops[i]) {
                if (shop.power >= needed) {
                    minCost = min(minCost, shop.cost);
                }
            }
            if (minCost == LLONG_MAX) {
                cout << -1 << endl;
                return 0;
            }
            totalCost += minCost;
            currentEnergy = shops[i][min_element(shops[i].begin(), shops[i].end(), [](const Store &a, const Store &b) {
                return a.cost < b.cost;
            }) - shops[i].begin()].power;
        }
        currentEnergy -= energy[i];
    }

    cout << totalCost << endl;
    return 0;
}
