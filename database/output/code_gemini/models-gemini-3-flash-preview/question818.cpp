/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    // Use a vector to store the sum of each column. 
    // Given N, M <= 1000 and values up to 100, the maximum sum is 100,000, 
    // which fits in a standard int. However, using long long is safer 
    // if the "millions" were provided as full numbers.
    vector<long long> col_sums(M, 0);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            long long value;
            cin >> value;
            col_sums[j] += value;
        }
    }

    // According to the problem, choosing a North-South street and its side
    // is equivalent to selecting a single column and calculating its sum.
    // The goal is to find the minimum of these column sums.
    long long min_cost = col_sums[0];
    for (int j = 1; j < M; ++j) {
        if (col_sums[j] < min_cost) {
            min_cost = col_sums[j];
        }
    }

    cout << min_cost << endl;

    return 0;
}