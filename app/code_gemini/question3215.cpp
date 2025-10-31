/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

bool check(long long time_limit, int n, int m, const std::vector<long long>& t) {
    int members_needed = 1;
    long long current_member_time = 0;

    for (int i = 0; i < m; ++i) {
        if (t[i] > time_limit) {
            return false;
        }
        if (current_member_time + t[i] <= time_limit) {
            current_member_time += t[i];
        } else {
            members_needed++;
            current_member_time = t[i];
        }
    }
    return members_needed <= n;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<long long> t(m);
    long long low = 0;
    long long high = 0;

    for (int i = 0; i < m; ++i) {
        std::cin >> t[i];
        high += t[i];
        if (t[i] > low) {
            low = t[i];
        }
    }

    long long ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (check(mid, n, m, t)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
