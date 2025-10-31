/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <bitset>

const int MAX_SUM = 1024 * 1024;

void solve_case(int case_num) {
    int n;
    std::cin >> n;

    std::vector<int> v(n);
    int total_sum = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
        total_sum += v[i];
    }

    std::bitset<MAX_SUM> dp;
    dp[0] = 1;

    for (int val : v) {
        dp |= (dp << val);
    }

    int h0 = 0;
    for (int i = total_sum / 2; i >= 0; --i) {
        if (dp[i]) {
            h0 = i;
            break;
        }
    }

    int h1 = total_sum - h0;

    std::cout << "caso " << case_num << ": " << h0 << " " << h1 << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int m;
    if (!(std::cin >> m)) {
        return 0;
    }

    for (int i = 0; i < m; ++i) {
        solve_case(i);
    }

    return 0;
}
