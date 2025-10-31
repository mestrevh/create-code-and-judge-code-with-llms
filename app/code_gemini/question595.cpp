/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
vector<int> cards;
int dp[1001][1001];

int solve(int i, int j) {
    if (i > j) {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int score_if_left;
    if (cards[i + 1] >= cards[j]) {
        score_if_left = cards[i] + solve(i + 2, j);
    } else {
        score_if_left = cards[i] + solve(i + 1, j - 1);
    }

    int score_if_right;
    if (cards[i] >= cards[j - 1]) {
        score_if_right = cards[j] + solve(i + 1, j - 1);
    } else {
        score_if_right = cards[j] + solve(i, j - 2);
    }
    
    return dp[i][j] = max(score_if_left, score_if_right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int game_num = 1;
    while (cin >> n && n != 0) {
        cards.resize(n);
        long long total_sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> cards[i];
            total_sum += cards[i];
        }

        memset(dp, -1, sizeof(dp));

        int p1_score = solve(0, n - 1);
        long long diff = (long long)p1_score - (total_sum - p1_score);
        
        cout << "In game " << game_num++ << ", the greedy strategy might lose by as many as " << diff << " points.\n";
    }

    return 0;
}
