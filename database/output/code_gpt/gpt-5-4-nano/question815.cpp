/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int IA, IB, FA, FB;
    if (!(cin >> IA >> IB >> FA >> FB)) return 0;

    queue<pair<int,int>> q;
    map<pair<int,int>, int> dist;
    auto start = make_pair(IA, IB);
    auto goal = make_pair(FA, FB);

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        auto [a, b] = q.front(); q.pop();
        int d = dist[{a,b}];
        if (make_pair(a,b) == goal) {
            cout << d << "\n";
            return 0;
        }

        int na = a ^ 1;
        int nb = b;
        if (!dist.count({na, nb})) {
            dist[{na, nb}] = d + 1;
            q.push({na, nb});
        }

        na = a ^ 1;
        nb = b ^ 1;
        if (!dist.count({na, nb})) {
            dist[{na, nb}] = d + 1;
            q.push({na, nb});
        }
    }

    return 0;
}