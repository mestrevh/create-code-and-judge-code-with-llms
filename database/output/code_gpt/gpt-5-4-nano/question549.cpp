/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    long long seed, a, b, c;
    while (cin >> N >> seed >> a >> b >> c) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long x = seed;
        for (int i = 0; i < N; i++) {
            if (i == 0) x = seed;
            else x = (x * a + b) % c;
            pq.push(x);
        }

        long long sum = 0;
        long long cost = 0;

        while (pq.size() > 1) {
            long long t1 = pq.top(); pq.pop();
            long long t2 = pq.top(); pq.pop();
            long long s = t1 + t2;
            cost += s;
            pq.push(s);
        }

        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }

        cout << sum << " " << cost << "\n";
    }
    return 0;
}