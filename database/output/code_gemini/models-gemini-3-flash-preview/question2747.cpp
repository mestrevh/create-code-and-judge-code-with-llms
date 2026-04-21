/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, h;
    if (!(cin >> n >> m >> h)) return 0;

    ll X, Y, Z;
    if (!(cin >> X >> Y >> Z)) return 0;

    ll P, Q, R;
    if (!(cin >> P >> Q >> R)) return 0;

    const ll MOD = 1000000007;
    const ll inv2 = 500000004;
    const ll inv6 = 166666668;

    X %= MOD;
    Y %= MOD;
    Z %= MOD;
    P %= MOD;
    Q %= MOD;
    R %= MOD;

    ll n_mod = n % MOD;
    ll m_mod = m % MOD;
    ll h_mod = h % MOD;

    ll n0 = n_mod;
    ll n1 = (n_mod * ((n - 1) % MOD)) % MOD * inv2 % MOD;

    ll m0 = m_mod;
    ll m1 = (m_mod * ((m - 1) % MOD)) % MOD * inv2 % MOD;
    ll m2 = (m_mod * ((m - 1) % MOD)) % MOD * ((2 * m_mod + MOD - 1) % MOD) % MOD * inv6 % MOD;

    ll h0 = h_mod;
    ll h1 = (h_mod * ((h - 1) % MOD)) % MOD * inv2 % MOD;

    // The total sum is the sum of c(i,k) for i from 0 to n-1 and k from 0 to h-1.
    // c(i,k) = sum over j from 0 to m-1 of (iX + jY + Z) * (jP + kQ + R)
    // S = sum_i sum_k sum_j [ (iX + Z)(jP + kQ + R) + jY(jP + kQ + R) ]
    // S = (X*N1 + Z*N0) * (P*M1*H0 + Q*M0*H1 + R*M0*H0) + N0*Y * (P*M2*H0 + Q*M1*H1 + R*M1*H0)

    ll term_A = (X * n1 % MOD + Z * n0 % MOD) % MOD;
    ll term_B = (P * m1 % MOD * h0 % MOD + Q * m0 % MOD * h1 % MOD + R * m0 % MOD * h0 % MOD) % MOD;
    
    ll term_C = (Y * n0 % MOD);
    ll term_D = (P * m2 % MOD * h0 % MOD + Q * m1 % MOD * h1 % MOD + R * m1 % MOD * h0 % MOD) % MOD;

    ll ans = (term_A * term_B % MOD + term_C * term_D % MOD) % MOD;

    cout << ans << endl;

    return 0;
}