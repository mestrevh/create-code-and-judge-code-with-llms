/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int N, int P, vector<int>& values, vector<int>& weights) {
    if (N == 0 || P == 0) return 0;
    if (weights[N - 1] > P) return knapsack(N - 1, P, values, weights);
    return max(knapsack(N - 1, P, values, weights),
               values[N - 1] + knapsack(N - 1, P - weights[N - 1], values, weights));
}

int main() {
    int N, P;
    cin >> N >> P;
    vector<int> values(N), weights(N);
    for (int i = 0; i < N; ++i) cin >> values[i];
    for (int i = 0; i < N; ++i) cin >> weights[i];
    
    cout << knapsack(N, P, values, weights) << endl;
    return 0;
}
