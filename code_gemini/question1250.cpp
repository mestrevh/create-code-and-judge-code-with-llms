/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <climits>

long long calculate_clodes_turns(long long k, long long V2, long long D1) {
    long long current_D1 = D1 + k * 50;
    if (current_D1 <= 0) return LLONG_MAX;
    long long attack_turns = (V2 + current_D1 - 1) / current_D1;
    return k + attack_turns;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    while (n--) {
        long long V1, V2, D1, D2;
        std::cin >> V1 >> V2 >> D1 >> D2;

        long long turns_bezaliel_wins = (V1 + D2 - 1) / D2;

        long long l = 0;
        long long r = (V1 - 1) / D2;
        
        if (r < 0) r = 0;

        while (r - l >= 3) {
            long long m1 = l + (r - l) / 3;
            long long m2 = r - (r - l) / 3;
            if (calculate_clodes_turns(m1, V2, D1) < calculate_clodes_turns(m2, V2, D1)) {
                r = m2;
            } else {
                l = m1;
            }
        }

        long long min_turns_clodes = LLONG_MAX;
        for (long long k = l; k <= r; ++k) {
            min_turns_clodes = std::min(min_turns_clodes, calculate_clodes_turns(k, V2, D1));
        }
        
        if (l == 0 && r == 0 && (V1 - 1) / D2 < 0) {
            min_turns_clodes = calculate_clodes_turns(0, V2, D1);
        }


        if (min_turns_clodes <= turns_bezaliel_wins) {
            std::cout << "Clodes\n";
        } else {
            std::cout << "Bezaliel\n";
        }
    }
    return 0;
}
