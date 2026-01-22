/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

bool can_survive(int days, int people, const std::vector<int>& counts) {
    if (days == 0) {
        return true;
    }
    int supported_people = 0;
    for (size_t i = 1; i < counts.size(); ++i) {
        supported_people += counts[i] / days;
    }
    return supported_people >= people;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> counts(101, 0);
    for (int i = 0; i < m; ++i) {
        int food_type;
        std::cin >> food_type;
        counts[food_type]++;
    }

    int low = 0;
    int high = m;
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (mid == 0) {
            low = mid + 1;
            continue;
        }
        if (can_survive(mid, n, counts)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
