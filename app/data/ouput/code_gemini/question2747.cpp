/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using ll = long long;
using i128 = __int128;

const ll MOD = 1000000007;

ll mul(ll a, ll b) {
    return (ll)((i128)a * b % MOD);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n, m, h;
    ll X, Y, Z;
    ll P, Q, R;

    std::cin >> n >> m >> h;
    std::cin >> X >> Y >> Z;
    std::cin >> P >> Q >> R;
    
    const ll inv2 = 500000004;
    const ll inv6 = 166666668;

    ll n_mod = n % MOD;
    ll m_mod = m % MOD;
    ll h_mod = h % MOD;
    ll X_mod = X % MOD;
    ll Y_mod = Y % MOD;
    ll Z_mod = Z % MOD;
    ll P_mod = P % MOD;
    ll Q_mod = Q % MOD;
    ll R_mod = R % MOD;

    ll n_minus_1_mod = (n - 1) % MOD;
    ll m_minus_1_mod = (m - 1) % MOD;
    ll h_minus_1_mod = (h - 1) % MOD;
    ll m_term_2m_minus_1_mod = (mul(2, m_mod) - 1 + MOD) % MOD;

    ll C1 = mul(n_mod, Y_mod);
    
    ll C2_term = mul(X_mod, n_minus_1_mod);
    C2_term = mul(C2_term, inv2);
    C2_term = (C2_term + Z_mod) % MOD;
    ll C2 = mul(n_mod, C2_term);

    ll D1 = mul(h_mod, P_mod);
    
    ll D2_term = mul(Q_mod, h_minus_1_mod);
    D2_term = mul(D2_term, inv2);
    D2_term = (D2_term + R_mod) % MOD;
    ll D2 = mul(h_mod, D2_term);

    ll sum_k0 = m_mod;
    
    ll sum_k1 = mul(m_minus_1_mod, m_mod);
    sum_k1 = mul(sum_k1, inv2);

    ll sum_k2 = mul(m_minus_1_mod, m_mod);
    sum_k2 = mul(sum_k2, m_term_2m_minus_1_mod);
    sum_k2 = mul(sum_k2, inv6);

    ll S_coeff2 = mul(C1, D1);
    ll S_coeff1 = (mul(C1, D2) + mul(C2, D1)) % MOD;
    ll S_coeff0 = mul(C2, D2);

    ll term2 = mul(S_coeff2, sum_k2);
    ll term1 = mul(S_coeff1, sum_k1);
    ll term0 = mul(S_coeff0, sum_k0);

    ll final_sum = (term2 + term1) % MOD;
    final_sum = (final_sum + term0) % MOD;

    std::cout << final_sum << std::endl;

    return 0;
}
