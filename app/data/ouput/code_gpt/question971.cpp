/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

struct Edge {
    int from, to, cost;
    bool operator<(const Edge &e) const {
        return cost > e.cost;
    }
};

int main() {
    int L;
    cin >> L;
    for (int k = 0; k < L; ++k) {
        int N;
        cin >> N;
        vector<pair<int, int>> warehouses(N);
        for (int i = 0; i < N; ++i) {
            cin >> warehouses[i].first >> warehouses[i].second;
        }
        priority_queue<Edge> pq;
        vector<bool> inMST(N, false);
        int totalCost = 0;
        
        inMST[0] = true;
        for (int i = 1; i < N; ++i) {
            int cost = abs(warehouses[0].first - warehouses[i].first) + 
                       abs(warehouses[0].second - warehouses[i].second);
            pq.push({0, i, cost});
        }

        while (!pq.empty()) {
            Edge e = pq.top();
            pq.pop();
            if (inMST[e.to]) continue;
            inMST[e.to] = true;
            totalCost += e.cost;

            for (int i = 0; i < N; ++i) {
                if (!inMST[i]) {
                    int cost = abs(warehouses[e.to].first - warehouses[i].first) + 
                               abs(warehouses[e.to].second - warehouses[i].second);
                    pq.push({e.to, i, cost});
                }
            }
        }

        cout << k << ": " << totalCost << endl;
        if (k < L - 1) cin.ignore(); // move to the next case
    }
    return 0;
}
