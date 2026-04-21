/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

long long fibRec(int n, vector<long long>& memo) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    if (memo[n] != -1) return memo[n];
    memo[n] = fibRec(n - 1, memo) + fibRec(n - 2, memo);
    return memo[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double X, Z;
    int Y, K;

    if (!(cin >> X)) return 0;
    cin >> Y;
    cin >> Z;
    cin >> K;

    int maxN = max(Y, K);
    vector<long long> memo(maxN + 1, -1);
    memo[0] = 0;
    if (maxN >= 1) memo[1] = 1;

    long long tVal = fibRec(Y, memo);
    memo.assign(maxN + 1, -1);
    memo[0] = 0;
    if (maxN >= 1) memo[1] = 1;
    long long gVal = fibRec(K, memo);

    cout << (X > (double)tVal ? "Nao foi dessa vez!! Troy nao teve coragem o suficiente."
                                  : "Esse pode ser o comeco de algo novo!! Troy vai cantar!!")
         << "\n";
    cout << (Z > (double)gVal ? "Nao foi dessa vez!! Gabriella nao teve coragem o suficiente."
                               : "Esse pode ser o comeco de algo novo!! Gabriella vai cantar!!");
    return 0;
}