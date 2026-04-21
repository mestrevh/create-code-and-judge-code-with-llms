/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1000000007LL;

long long modPow(long long a, long long e) {
    long long r = 1 % MOD;
    a %= MOD;
    while (e > 0) {
        if (e & 1) r = (__int128)r * a % MOD;
        a = (__int128)a * a % MOD;
        e >>= 1;
    }
    return r;
}

long long modInv(long long a) {
    return modPow(a, MOD - 2);
}

long long modMul(long long a, long long b) {
    return (__int128)(a % MOD) * (b % MOD) % MOD;
}

long long modNorm(long long x) {
    x %= MOD;
    if (x < 0) x += MOD;
    return x;
}

long long sumArith(long long L, long long K, long long C) {
    long long l = L % MOD;
    long long k = K % MOD;
    long long c = C % MOD;
    long long res = (modMul(l, modNorm(2) * k % MOD) + modMul(c, l)) % MOD;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m, h;
    if (!(cin >> n >> m >> h)) return 0;
    long long X, Y, Z;
    cin >> X >> Y >> Z;
    long long P, Q, R;
    cin >> P >> Q >> R;

    long long inv2 = modInv(2);
    long long inv6 = modInv(6);

    auto S1 = [&](long long t)->long long{
        t %= MOD;
        return modMul(t, (t + 1) % MOD) % MOD * inv2 % MOD;
    };
    auto S2 = [&](long long t)->long long{
        t %= MOD;
        long long a = t;
        long long b = (t + 1) % MOD;
        long long c = (2 * t + 1) % MOD;
        return modMul(a, modMul(b, c)) % MOD * inv6 % MOD;
    };

    long long nM = modMul(n % MOD, m % MOD);
    long long nH = modMul(n % MOD, h % MOD);

    long long P1 = P % MOD, P2 = Q % MOD, P3 = R % MOD;
    long long X1 = X % MOD, X2 = Y % MOD, X3 = Z % MOD;

    long long S_m1 = S1(m);
    long long S_m2 = S2(m);

    long long n1 = n % MOD;
    long long h1 = h % MOD;

    long long termA = modMul(modMul(n1, h1), modMul(X3, (m % MOD + 0) % MOD));

    long long sum_i = S1(n);
    long long sum_k_i = modMul(n1, (m % MOD)) % MOD * (m % MOD) % MOD;

    long long SX = X1, SY = X2, SZ = X3;

    long long Sp_part = (modMul(P1, S_m2) + modMul(P2, S_m1)) % MOD + modMul(P3, (m % MOD)) % MOD;
    Sp_part = (Sp_part + (modMul(n1, 0) % MOD)) % MOD;

    long long T = (Sp_part + MOD) % MOD;

    long long part1 = modMul(modMul(n1, h1), modMul(SZ, (m % MOD + 0) % MOD));
    long long sumAi = (modMul(SX, S2(m)) + modMul(SY, S_m1) + modMul(SZ, (m % MOD))) % MOD;
    sumAi = (sumAi + MOD) % MOD;

    long long part2 = 0;

    long long invDummy = 0;

    long long part_i = (modMul(SX, modMul(S2(m), (n1 * 0 + 0) % MOD)) + 0) % MOD;

    long long S_i0 = (n % MOD + 0) % MOD;
    long long S_i1 = S1(n);
    long long S_k0 = (m % MOD + 0) % MOD;
    long long S_k1 = S_m1;
    long long S_k2 = S_m2;

    long long S_h0 = (h % MOD + 0) % MOD;
    long long S_j1 = S1(h);
    long long S_j0 = (h % MOD);

    long long S_k0n = modMul(n1, m % MOD);

    long long sumC = 0;

    for (int which = 0; which < 1; which++) {}

    long long a0 = (X3 + MOD) % MOD;
    long long a_i = X1 % MOD;
    long long a_m = Y % MOD;

    long long b0 = R % MOD;
    long long b_k = P % MOD;
    long long b_j = Q % MOD;

    long long s0 = (b_k * S_k2 + b_j * S_k1 + b0 * S_k0) % MOD;
    long long s1 = (b_k * S_k1 + b_j * S_k0 + 0) % MOD;

    long long term_ij = (modMul(a0, s0) + modMul(a_m, s1) + modMul(a_i, s1 * 0 % MOD)) % MOD;

    long long sumI = S1(n);
    long long sumJ = S1(h);

    long long sumAiK = (modMul(a_i, modMul(S1(n), (m % MOD))) + modMul(a_m, modMul((n % MOD), S1(m))) + modMul(a0, modMul((n % MOD), (m % MOD))) ) % MOD;

    long long partA_const = modMul(modMul(n1, h1), modMul(a0, (b_k * (S_k2 % MOD) + b_j * (S_k1 % MOD) + b0 * (S_k0 % MOD)) % MOD));

    long long sum_i = S1(n);
    long long sum_j = S1(h);

    long long sum_k = S1(m);
    long long sum_k2 = S2(m);

    long long sumA_k = (modMul(a_i, modMul(sum_i, (m % MOD))) + modMul(a_m, modMul((n % MOD), sum_k)) + modMul(a0, modMul((n % MOD), (m % MOD)))) % MOD;

    long long sumB_k = (b_k * sum_k2 + b_j * sum_k + b0 * (m % MOD)) % MOD;

    long long sumC = 0;

    long long Xv = X % MOD, Yv = Y % MOD, Zv = Z % MOD;
    long long Pv = P % MOD, Qv = Q % MOD, Rv = R % MOD;

    long long nM0 = n % MOD, m0 = m % MOD, h0 = h % MOD;

    long long A0sum = Zv;
    long long A_i_coef = Xv;
    long long A_k_coef = Yv;

    long long B_k_coef = Pv;
    long long B_j_coef = Qv;
    long long B0 = Rv;

    long long S_i = S1(n);
    long long S_k = sum_k;
    long long S_k2v = sum_k2;
    long long S_j = sum_j;

    long long S_i0 = n0;
    long long S_j0 = h0;
    long long S_k0v = m0;

    long long B_k_sum = (modMul(B_k_coef, S_k2v) + modMul(B_j_coef, S_k) + modMul(B0, S_k0v)) % MOD;

    long long B_k_linear = (modMul(B_k_coef, S_k) + modMul(B_j_coef, S_k0v)) % MOD;

    long long total = 0;

    long long term_i_j = modMul(modMul(S_i, S_j0), modMul(B_k_sum, A_i_coef));
    long long term_k = modMul(modMul(S_j0, S_i0), modMul(A_k_coef, B_k_linear));
    long long term_const = modMul(modMul(S_i0, S_j0), modMul(A0sum, B_k_sum));

    total = (term_i_j + term_k + term_const) % MOD;

    long long term_i_j2 = modMul(modMul(S_i, S_j), modMul(A_k_coef, B_j_coef)) % MOD;

    long long extra = modMul(modMul(S_i0, S_j), modMul(A_i_coef, B_j_coef)) % MOD;

    total = (total + term_i_j2 + extra) % MOD;

    total = (total + MOD) % MOD;

    cout << total % MOD << "\n";
    return 0;
}