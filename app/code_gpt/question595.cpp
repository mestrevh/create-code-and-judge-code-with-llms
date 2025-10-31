/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1001][1001];

int maxDifference(const vector<int>& cards, int left, int right) {
    if (left > right) return 0;
    if (dp[left][right] != -1) return dp[left][right];

    int takeLeft = cards[left] - maxDifference(cards, left + 1, right);
    int takeRight = cards[right] - maxDifference(cards, left, right - 1);
    
    dp[left][right] = max(takeLeft, takeRight);
    return dp[left][right];
}

int greedyScore(const vector<int>& cards, int left, int right) {
    int score = 0;
    while (left <= right) {
        if (cards[left] > cards[right]) {
            score += cards[left++];
        } else {
            score += cards[right--];
        }
    }
    return score;
}

int main() {
    int gameNumber = 1;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        vector<int> cards(n);
        for (int i = 0; i < n; ++i) {
            cin >> cards[i];
        }

        memset(dp, -1, sizeof(dp));
        int firstPlayerScore = maxDifference(cards, 0, n - 1);
        int secondPlayerScore = greedyScore(cards, 0, n - 1);
        
        cout << "In game " << gameNumber++ << ", the greedy strategy might lose by as many as " 
             << firstPlayerScore - secondPlayerScore << " points." << endl;
    }
    return 0;
}
