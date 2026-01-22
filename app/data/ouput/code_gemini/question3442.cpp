/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using i128 = __int128;

i128 V1, D1, V2, D2;

i128 calculate_required_health(i128 k) {
    if (k < 0) {
        return (i128)1 << 126;
    }
    if (V1 <= D2 * k) {
        return (i128)1 << 126;
    }

    i128 d1_new = D1 + 50 * k;
    i128 t_clodes_attacks = (V2 + d1_new - 1) / d1_new;
    
    i128 total_turns = k + t_clodes_attacks;
    i128 bezaliel_attacks = total_turns - 1;
    
    return D2 * bezaliel_attacks;
}

void solve() {
    long long v1_ll, d1_ll, v2_ll, d2_ll;
    std::cin >> v1_ll >> d1_ll >> v2_ll >> d2_ll;
    V1 = v1_ll;
    D1 = d1_ll;
    V2 = v2_ll;
    D2 = d2_ll;

    i128 l = 0;
    i128 r = (V1 > D2) ? (V1 - 1) / D2 : 0;

    for(int i = 0; i < 200; ++i) {
        if (l >= r) break;
        i128 m1 = l + (r - l) / 3;
        i128 m2 = r - (r - l) / 3;
        if (calculate_required_health(m1) < calculate_required_health(m2)) {
            r = m2 - 1;
        } else {
            l = m1 + 1;
        }
    }
    
    i128 min_required_health = (i128)1 << 126;

    i128 start_k = (l > 10) ? l - 10 : 0;
    i128 end_k = l + 10;

    for (i128 k = start_k; k <= end_k; ++k) {
         min_required_health = std::min(min_required_health, calculate_required_health(k));
    }
    
    // Also check the case with 0 buffs as it is a boundary condition.
    min_required_health = std::min(min_required_health, calculate_required_health(0));

    if (V1 > min_required_health) {
        std::cout << "Clodes\n";
    } else {
        std::cout << "Bezaliel\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    while (n--) {
        solve();
    }
    
    return 0;
}
