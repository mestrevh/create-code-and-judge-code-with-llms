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

    vector<pair<int,int>> scheduled;
    scheduled.reserve(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        scheduled.push_back({a, b});
    }

    vector<int> extras;
    extras.reserve(M);
    for (int i = 0; i < M; i++) {
        int c;
        cin >> c;
        extras.push_back(c);
    }

    sort(scheduled.begin(), scheduled.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int c : extras) pq.push(c);

    long long endTime = 0;
    if (!scheduled.empty()) endTime = scheduled.back().second;

    if (scheduled.empty()) {
        endTime = 0;
        int total = 0;
        vector<int> all;
        all.reserve(M);
        while (!pq.empty()) {
            all.push_back(pq.top());
            pq.pop();
        }
        sort(all.begin(), all.end());
        long long time = 0;
        for (int c : all) {
            time += c;
            if (time <= 100000) total++;
        }
        cout << total << "\n";
        return 0;
    }

    long long current = 0;
    long long hospitalEnd = endTime;
    for (auto [a, b] : scheduled) {
        if (current < a) {
            long long gap = a - current;
            while (!pq.empty() && pq.top() <= gap) {
                int c = pq.top();
                pq.pop();
                gap -= c;
                total:
                current += c;
            }
        }
        current = max(current, (long long)b);
    }

    if (current < hospitalEnd) {
        long long gap = hospitalEnd - current;
        while (!pq.empty() && pq.top() <= gap) {
            int c = pq.top();
            pq.pop();
            gap -= c;
            current += c;
        }
    }

    int ans = 0;
    {
        vector<int> remaining;
        while (!pq.empty()) {
            remaining.push_back(pq.top());
            pq.pop();
        }
        ans = M - (int)remaining.size();
    }

    cout << ans << "\n";
    return 0;
}