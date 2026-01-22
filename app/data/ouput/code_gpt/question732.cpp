/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <numeric>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N, M, K;
        cin >> N >> M >> K;
        vector<int> P(N), Q(M);
        for (int i = 0; i < N; ++i) cin >> P[i];
        for (int i = 0; i < M; ++i) cin >> Q[i];

        sort(P.begin(), P.end());
        int targetSum = 0;
        for (int i = 0; i < K; ++i) targetSum += P[i];
        
        int minLength = INT_MAX;
        int currentSum = 0, left = 0;

        for (int right = 0; right < M; ++right) {
            currentSum += Q[right];
            while (currentSum >= targetSum) {
                minLength = min(minLength, right - left + 1);
                currentSum -= Q[left++];
            }
        }
        
        cout << "Caso #" << t << ": ";
        if (minLength == INT_MAX)
            cout << -1 << endl;
        else
            cout << minLength << endl;
    }
    return 0;
}
