/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int V[1005];
long long memo[1005][1005];
bool vis[1005][1005];

long long solve(int i, int j) {
    if (i > j) return 0;
    if (vis[i][j]) return memo[i][j];

    // Choice 1: First player takes the left card V[i]
    long long res1;
    int ni = i + 1, nj = j;
    // Second player follows greedy strategy on range [ni, nj]
    if (ni <= nj) {
        if (V[ni] >= V[nj]) {
            // Greedy picks leftmost V[ni] if V[ni] >= V[nj]
            res1 = (long long)V[i] - V[ni] + solve(ni + 1, nj);
        } else {
            // Greedy picks rightmost V[nj]
            res1 = (long long)V[i] - V[nj] + solve(ni, nj - 1);
        }
    } else {
        res1 = V[i];
    }

    // Choice 2: First player takes the right card V[j]
    long long res2;
    int mi = i, mj = j - 1;
    // Second player follows greedy strategy on range [mi, mj]
    if (mi <= mj) {
        if (V[mi] >= V[mj]) {
            // Greedy picks leftmost V[mi] if V[mi] >= V[mj]
            res2 = (long long)V[j] - V[mi] + solve(mi + 1, mj);
        } else {
            // Greedy picks rightmost V[mj]
            res2 = (long long)V[j] - V[mj] + solve(mi, mj - 1);
        }
    } else {
        res2 = V[j];
    }

    vis[i][j] = true;
    memo[i][j] = max(res1, res2);
    return memo[i][j];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, gameCount = 1;
    while (cin >> n && n != 0) {
        for (int i = 0; i < n; i++) {
            cin >> V[i];
        }

        // Reset DP state for each game
        for (int i = 0; i < n; i++) {
            memset(vis[i], 0, sizeof(bool) * n);
        }

        long long maxDifference = solve(0, n - 1);

        cout << "In game " << gameCount++ << ", the greedy strategy might lose by as many as " << maxDifference << " points.\n";
    }

    return 0;
}