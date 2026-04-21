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
    vector<pair<int,int>> buses(N);
    for (int i = 0; i < N; i++) {
        int C, P;
        cin >> C >> P;
        buses[i] = {C, P};
    }
    sort(buses.begin(), buses.end(), [](const auto& a, const auto& b){
        if (a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    });
    
    priority_queue<int, vector<int>, greater<int>> pq;
    int maxSimultaneous = 0;
    for (auto &bp : buses) {
        int C = bp.first, P = bp.second;
        while (!pq.empty() && pq.top() <= C) pq.pop();
        pq.push(P);
        maxSimultaneous = max(maxSimultaneous, (int)pq.size());
    }
    
    cout << maxSimultaneous * 20 << "\n";
    return 0;
}