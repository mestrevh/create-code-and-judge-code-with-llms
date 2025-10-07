/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

bool check(long long r, int n, int m, const std::vector<int>& a, const std::vector<int>& b) {
    int city_idx = 0;
    int antenna_idx = 0;
    while (city_idx < n) {
        if (antenna_idx >= m) {
            return false;
        }

        long long coverage_start = (long long)b[antenna_idx] - r;
        long long coverage_end = (long long)b[antenna_idx] + r;

        if (a[city_idx] < coverage_start) {
            return false;
        }

        if (a[city_idx] > coverage_end) {
            antenna_idx++;
            continue;
        }
        
        int last_covered_city_idx = city_idx;
        while (last_covered_city_idx < n && (long long)a[last_covered_city_idx] <= coverage_end) {
            last_covered_city_idx++;
        }
        
        city_idx = last_covered_city_idx;
        antenna_idx++;
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }

    long long low = 0;
    long long high = 2000000001LL;
    long long ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (check(mid, n, m, a, b)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
