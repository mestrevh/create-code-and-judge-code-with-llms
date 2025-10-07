/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>

const long long IMPOSSIBLE = -1;

long long solve(long long hall_len_m, long long hall_wid_m, int plank_wid_cm, const std::vector<int>& planks_m) {
    if (hall_len_m <= 0 || hall_wid_m <= 0) return 0;

    long long hall_len_cm = hall_len_m * 100;
    long long hall_wid_cm = hall_wid_m * 100;

    if (plank_wid_cm <= 0 || hall_wid_cm % plank_wid_cm != 0) {
        return IMPOSSIBLE;
    }

    long long num_rows_needed = hall_wid_cm / plank_wid_cm;
    if (num_rows_needed == 0) return 0;
    
    long long planks_used = 0;

    std::map<long long, int> counts;
    for (int p_len_m : planks_m) {
        counts[static_cast<long long>(p_len_m) * 100]++;
    }

    if (counts.count(hall_len_cm)) {
        long long can_use = std::min(num_rows_needed, (long long)counts[hall_len_cm]);
        planks_used += can_use;
        num_rows_needed -= can_use;
        counts[hall_len_cm] -= can_use;
    }

    if (num_rows_needed == 0) {
        return planks_used;
    }

    for (auto it = counts.begin(); it != counts.end(); ++it) {
        if (num_rows_needed == 0) break;
        
        long long len1 = it->first;
        long long count1 = it->second;

        if (count1 <= 0) continue;
        if (len1 * 2 > hall_len_cm) break;

        long long len2 = hall_len_cm - len1;

        if (len1 == len2) {
            long long num_pairs = count1 / 2;
            long long can_use = std::min(num_rows_needed, num_pairs);
            planks_used += can_use * 2;
            num_rows_needed -= can_use;
        } else {
            if (counts.count(len2)) {
                long long count2 = counts[len2];
                long long num_pairs = std::min(count1, count2);
                long long can_use = std::min(num_rows_needed, num_pairs);

                planks_used += can_use * 2;
                num_rows_needed -= can_use;
                it->second -= can_use;
                counts[len2] -= can_use;
            }
        }
    }

    if (num_rows_needed == 0) {
        return planks_used;
    } else {
        return IMPOSSIBLE;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long M, N;
    while (std::cin >> M >> N && (M != 0 || N != 0)) {
        int L;
        int K;
        std::cin >> L;
        std::cin >> K;
        std::vector<int> planks(K);
        for (int i = 0; i < K; ++i) {
            std::cin >> planks[i];
        }

        long long ans1 = solve(M, N, L, planks);
        long long ans2 = solve(N, M, L, planks);

        if (ans1 == IMPOSSIBLE && ans2 == IMPOSSIBLE) {
            std::cout << "impossivel\n";
        } else if (ans1 == IMPOSSIBLE) {
            std::cout << ans2 << "\n";
        } else if (ans2 == IMPOSSIBLE) {
            std::cout << ans1 << "\n";
        } else {
            std::cout << std::min(ans1, ans2) << "\n";
        }
    }

    return 0;
}
