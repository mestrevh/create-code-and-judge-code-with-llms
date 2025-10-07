/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> findFairX(int n, const vector<int>& p, const vector<pair<int, int>>& queries) {
    vector<int> result;
    
    for (const auto& query : queries) {
        int L = query.first - 1, R = query.second - 1;
        vector<bool> visited(n + 1, false);
        int terminationCount = 0, nonTerminationCount = 0;

        for (int i = L; i <= R; i++) {
            int x = p[i];
            while (x > R + 1 || visited[x]) {
                if (x <= R + 1) break;
                visited[x] = true;
                x = p[x - 1];
            }
            if (x <= R + 1) {
                terminationCount++;
            } else {
                nonTerminationCount++;
            }
        }
        
        int bestX = L + 1;
        double bestDiff = abs(terminationCount - nonTerminationCount);
        
        for (int x = L + 1; x <= R + 1; x++) {
            visited.assign(n + 1, false);
            terminationCount = 0;
            nonTerminationCount = 0;

            for (int i = L; i <= R; i++) {
                int cur = p[i];
                while (cur > R + 1 || visited[cur]) {
                    if (cur <= R + 1) break;
                    visited[cur] = true;
                    cur = p[cur - 1];
                }
                if (cur <= x) {
                    terminationCount++;
                } else {
                    nonTerminationCount++;
                }
            }
            double diff = abs(terminationCount - nonTerminationCount);
            if (diff < bestDiff || (diff == bestDiff && x < bestX)) {
                bestX = x;
                bestDiff = diff;
            }
        }
        result.push_back(bestX);
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].first >> queries[i].second;
    }
    
    vector<int> result = findFairX(n, p, queries);
    for (int x : result) {
        cout << x << '\n';
    }
    
    return 0;
}
