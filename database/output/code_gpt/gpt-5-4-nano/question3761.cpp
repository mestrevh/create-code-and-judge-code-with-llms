/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long Z, N;
    if (!(cin >> Z >> N)) return 0;

    long long X;
    cin >> X;

    long long totalDist = 0;
    long long currentFloor = 0;

    struct Req { long long floor; long long people; };
    queue<Req> q;

    for (long long i = 0; i < X; i++) {
        long long f, p;
        cin >> f >> p;
        q.push({f, p});
    }

    while (!q.empty()) {
        vector<long long> stops;
        long long capRemaining = N;

        while (!q.empty()) {
            auto [f, p] = q.front();
            if (p == 0) { q.pop(); continue; }

            if (p <= capRemaining) {
                capRemaining -= p;
                stops.push_back(f);
                q.pop();
                if (capRemaining == 0) break;
            } else {
                long long stay = p - capRemaining;
                q.pop();
                q.push({f, stay});
                stops.push_back(f);
                capRemaining = 0;
                break;
            }
        }

        for (long long f : stops) totalDist += 2 * f;
    }

    cout << totalDist << "\n";
    return 0;
}