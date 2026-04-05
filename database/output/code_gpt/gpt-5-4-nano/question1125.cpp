/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<string> results;
    string cur;
    cur.reserve(2 * N);

    function<void(int,int)> dfs = [&](int leftUsed, int rightUsed) {
        if (leftUsed == N && rightUsed == N) {
            results.push_back(cur);
            return;
        }
        if (leftUsed < N) {
            cur.push_back('(');
            dfs(leftUsed + 1, rightUsed);
            cur.pop_back();
        }
        if (rightUsed < leftUsed) {
            cur.push_back(')');
            dfs(leftUsed, rightUsed + 1);
            cur.pop_back();
        }
    };

    dfs(0, 0);

    for (size_t i = 0; i < results.size(); i++) {
        cout << "[" << results[i] << "]";
        if (i + 1 < results.size()) cout << ",";
    }
    return 0;
}