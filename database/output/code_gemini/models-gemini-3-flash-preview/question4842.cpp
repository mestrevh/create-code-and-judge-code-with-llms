/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> get_scores(int x_s, int x_l, int y_s, int y_l, const string& X, const string& Y) {
    vector<int> prev(x_l + 1);
    vector<int> curr(x_l + 1);
    for (int i = 0; i <= x_l; i++) prev[i] = i * 2;
    if (y_l == 0) return prev;
    for (int j = 1; j <= y_l; j++) {
        curr[0] = j * 2;
        char y_char = Y[y_s + j - 1];
        for (int i = 1; i <= x_l; i++) {
            int cost = (X[x_s + i - 1] == y_char ? 0 : 1);
            int v1 = prev[i - 1] + cost;
            int v2 = curr[i - 1] + 2;
            int v3 = prev[i] + 2;
            curr[i] = (v1 <= v2 && v1 <= v3) ? v1 : (v2 <= v3 ? v2 : v3);
        }
        prev = curr;
    }
    return prev;
}

vector<int> get_scores_rev(int x_s, int x_l, int y_s, int y_l, const string& X, const string& Y) {
    vector<int> prev(x_l + 1);
    vector<int> curr(x_l + 1);
    for (int i = 0; i <= x_l; i++) prev[i] = i * 2;
    if (y_l == 0) return prev;
    for (int j = 1; j <= y_l; j++) {
        curr[0] = j * 2;
        char y_char = Y[y_s + y_l - j];
        for (int i = 1; i <= x_l; i++) {
            int cost = (X[x_s + x_l - i] == y_char ? 0 : 1);
            int v1 = prev[i - 1] + cost;
            int v2 = curr[i - 1] + 2;
            int v3 = prev[i] + 2;
            curr[i] = (v1 <= v2 && v1 <= v3) ? v1 : (v2 <= v3 ? v2 : v3);
        }
        prev = curr;
    }
    return prev;
}

void solve(int x_s, int x_l, int y_s, int y_l, const string& X, const string& Y, string& resX, string& resY) {
    if (y_l == 0) {
        for (int i = 0; i < x_l; i++) {
            resX += X[x_s + i];
            resY += '-';
        }
        return;
    }
    if (y_l == 1) {
        vector<vector<int>> dp(x_l + 1, vector<int>(2));
        for (int i = 0; i <= x_l; i++) dp[i][0] = i * 2;
        dp[0][1] = 2;
        for (int i = 1; i <= x_l; i++) {
            int cost = (X[x_s + i - 1] == Y[y_s] ? 0 : 1);
            int v1 = dp[i-1][0] + cost;
            int v2 = dp[i-1][1] + 2;
            int v3 = dp[i][0] + 2;
            dp[i][1] = (v1 <= v2 && v1 <= v3) ? v1 : (v2 <= v3 ? v2 : v3);
        }
        int i = x_l, j = 1;
        string sx = "", sy = "";
        while (i > 0 || j > 0) {
            int cost = (i > 0 && j > 0) ? (X[x_s + i - 1] == Y[y_s + j - 1] ? 0 : 1) : 1000000;
            if (i > 0 && j > 0 && dp[i][j] == dp[i-1][j-1] + cost) {
                sx += X[x_s + i - 1]; sy += Y[y_s + j - 1]; i--; j--;
            } else if (i > 0 && dp[i][j] == dp[i-1][j] + 2) {
                sx += X[x_s + i - 1]; sy += '-'; i--;
            } else {
                sx += '-'; sy += Y[y_s + j - 1]; j--;
            }
        }
        reverse(sx.begin(), sx.end());
        reverse(sy.begin(), sy.end());
        resX += sx; resY += sy;
        return;
    }
    int mid = y_l / 2;
    vector<int> L = get_scores(x_s, x_l, y_s, mid, X, Y);
    vector<int> R = get_scores_rev(x_s, x_l, y_s + mid, y_l - mid, X, Y);
    int min_v = 1000000, best_i = 0;
    for (int i = 0; i <= x_l; i++) {
        if (L[i] + R[x_l - i] < min_v) {
            min_v = L[i] + R[x_l - i];
            best_i = i;
        }
    }
    solve(x_s, best_i, y_s, mid, X, Y, resX, resY);
    solve(x_s + best_i, x_l - best_i, y_s + mid, y_l - mid, X, Y, resX, resY);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string X, Y;
    if (!(cin >> X >> Y)) return 0;
    vector<int> final_scores = get_scores(0, X.size(), 0, Y.size(), X, Y);
    cout << final_scores[X.size()] << "\n";
    string resX = "", resY = "";
    solve(0, X.size(), 0, Y.size(), X, Y, resX, resY);
    cout << resX << "\n";
    cout << resY << "\n";
    return 0;
}