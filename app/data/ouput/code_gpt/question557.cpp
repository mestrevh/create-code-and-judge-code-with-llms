/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <sstream>

using namespace std;

pair<int, string> matrixChainOrder(const vector<pair<int, int>>& p, int n) {
    vector<vector<int>> m(n, vector<int>(n, 0));
    vector<vector<int>> s(n, vector<int>(n, 0));

    for (int l = 2; l <= n; ++l) {
        for (int i = 0; i < n - l + 1; ++i) {
            int j = i + l - 1;
            m[i][j] = numeric_limits<int>::max();
            for (int k = i; k < j; ++k) {
                int q = m[i][k] + m[k + 1][j] + p[i].first * p[k + 1].first * p[j].second;
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    return {m[0][n - 1], constructOptimalOrder(s, 0, n - 1)};
}

string constructOptimalOrder(const vector<vector<int>>& s, int i, int j) {
    if (i == j) {
        return "A" + to_string(i + 1);
    } else {
        return "(" + constructOptimalOrder(s, i, s[i][j]) + " x " + constructOptimalOrder(s, s[i][j] + 1, j) + ")";
    }
}

int main() {
    int n, case_num = 1;
    while (cin >> n && n != 0) {
        vector<pair<int, int>> matrices(n);
        for (int i = 0; i < n; ++i) {
            cin >> matrices[i].first >> matrices[i].second;
        }

        vector<pair<int, int>> dimensions(n + 1);
        for (int i = 0; i < n; ++i) {
            dimensions[i] = matrices[i];
        }
        dimensions[n] = matrices[n - 1].second;

        auto result = matrixChainOrder(dimensions, n);
        cout << "Case " << case_num++ << ": " << result.second << endl;
    }
    return 0;
}
