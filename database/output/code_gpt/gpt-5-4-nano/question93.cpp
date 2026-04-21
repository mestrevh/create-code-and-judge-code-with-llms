/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

static inline __int128 to128(long long x){ return (__int128)x; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long H, n;
    while ( (cin >> H >> n) ) {
        if (H == 0 && n == 0) break;

        unsigned long long workers = (unsigned long long)n;
        unsigned long long notWorking = 0;
        __int128 sumHeight = 0;

        unsigned long long k = 1;
        __int128 currentHeight = (__int128)H;

        while (true) {
            if (k > workers) break;
            if (k == workers) {
                notWorking = k - 1;
                sumHeight += currentHeight;
                break;
            }
            sumHeight += currentHeight;
            k++;
            if (currentHeight % n == 0) currentHeight = currentHeight / n * (n + 1);
            else currentHeight = (currentHeight * (n + 1)) / n;
        }

        // The above loop didn't correctly compute since recurrence depends on depth; implement properly:
        // Recompute using integer arithmetic:
        unsigned long long m = workers;
        notWorking = 0;
        sumHeight = 0;

        unsigned long long depth = 0;
        __int128 h = (__int128)H;
        __int128 a = h; // height at level 0
        // At level i: number of cats = n^i, height = H / (n+1)^i
        // Workers are exactly n at height 1, thus total workers count is m = n (given).
        // However in this problem, "number of workers" refers to number of cats of height 1.
        // That means n^depth = m, where depth is such that height at that depth equals 1.
        // We can find depth by repeatedly multiplying by (n+1) until equals 1? Wait.
        // Let's use known property: height sequence: H, H/(n+1), H/(n+1)^2, ...
        // Since all heights are positive integers, there is some D such that H/(n+1)^D = 1.
        // The number of workers is n^D (each level multiplies by n cats per hat).
        // Therefore, input's second integer is workersCount m = n^D? But statement says second integer is number of workers (height one).
        // In examples:
        // 3 2 => workers=2, H=3. Need D s.t. 3/(2+1)^D=1 => 3/3^D=1 => D=1. Then workers count should be n^D = 2^1=2. Works.
        // 9 4 => H=9, m=4. (n+1)^D =? But n is workers per bigger hat, not given directly.
        // If workers per hat constant is n_hat, then D satisfies H/(n_hat+1)^D=1, and workers total = n_hat^D.
        // So second integer is n_hat^D? Not directly.
        // For 9 4: find n_hat from n_hat^D=4 and (n_hat+1)^D=9.
        // D=2 gives n_hat=2 (2^2=4) and (3)^2=9 yes.
        // So we must interpret input as: initial height H0, and number of smallest cats (workers) W.
        // Unknown n_hat (cats in each bigger hat) and depth D are such that:
        // H0 = (n_hat+1)^D, W = n_hat^D.
        // Because smallest cats height=1 and heights are integers.
        // Therefore n_hat and D can be derived by factoring W and H0 accordingly.
        // We just need:
        // not working cats count = total cats - workers
        // total cats = 1 + n_hat + n_hat^2 + ... + n_hat^D
        // = (n_hat^(D+1)-1)/(n_hat-1) if n_hat!=1 else D+1.
        // sum of heights = sum_{i=0..D} (number at level i)*(height at level i)
        // level i: count = n_hat^i, height = H0/(n_hat+1)^i
        // Since H0=(n_hat+1)^D, height at level i = (n_hat+1)^(D-i)
        // thus contribution = n_hat^i * (n_hat+1)^(D-i)
        // = (n_hat+1)^D * (n_hat/(n_hat+1))^i, but compute integers with __int128 via iterative formula:
        // Let term0 at i=0: (n_hat+1)^D = H0.
        // Next term i=1: count multiplied by n_hat and height divided by (n_hat+1):
        // term_{i+1} = term_i * n_hat / (n_hat+1).
        // All terms are integers.
        //
        // Need to find n_hat and D such that n_hat^D=W and (n_hat+1)^D=H0.
        // Then solve.
        //
        // Find D by iterating possible exponents from 1..60 using integer roots:
        long long W = n;
        long long n_hat = -1;
        int D = -1;

        // Handle case where W==1: then n_hat^D=1 => n_hat=1 or D=0. D>=1 because H0>0 and heights decrease to 1.
        if (W == 1) {
            // Then n_hat must be 1 and H0 must be 2^D.
            // Determine D as log2(H0).
            long long x = H;
            int d = 0;
            while (x % 2 == 0 && x > 1) { x /= 2; d++; }
            if (x == 1) {
                n_hat = 1;
                D = d;
            } else {
                // Fallback: try D=1 with n_hat=1 => H0=2. Otherwise inconsistent.
                if (H == 2) { n_hat = 1; D = 1; }
            }
        } else {
            // Try all possible D from 1..60 by finding integer n_hat = W^(1/D)
            // and checking (n_hat+1)^D == H.
            for (int d = 1; d <= 60; d++) {
                // compute integer root of W for exponent d
                long long lo = 1, hi = (long long)pow((long double)W, 1.0L/d) + 2;
                if (hi < 1) hi = 1;
                long long best = 0;
                while (lo <= hi) {
                    long long mid = (lo + hi) / 2;
                    __int128 p = 1;
                    for (int i = 0; i < d; i++) {
                        p *= mid;
                        if (p > (__int128)W) break;
                    }
                    if (p == (__int128)W) { best = mid; break; }
                    if (p < (__int128)W) lo = mid + 1;
                    else hi = mid - 1;
                }
                if (best == 0) {
                    // check if W is exact d-th power
                    __int128 p = 1;
                    long long mid = (long long)round(pow((long double)W, 1.0L/d));
                    (void)mid;
                } else {
                    long long candidate = best;
                    __int128 q = 1;
                    for (int i = 0; i < d; i++) {
                        q *= (candidate + 1);
                        if (q > (__int128)H) break;
                    }
                    if (q == (__int128)H) {
                        n_hat = candidate;
                        D = d;
                        break;
                    }
                }
            }
            // If not found, try D up to 30 with exact root by scanning using primes? but constraints unknown.
            // Likely input always consistent.
        }

        if (n_hat == -1 || D == -1) {
            // Inconsistent case: compute via direct simulation of hats without needing n_hat? Not possible.
            // We'll just output 0 and sum=H as a safeguard.
            cout << 0 << " " << H << "\n";
            continue;
        }

        // Compute notWorking = totalCats - workers
        __int128 totalCats = 0;
        if (n_hat == 1) {
            totalCats = (__int128)(D + 1);
        } else {
            __int128 p = 1;
            for (int i = 0; i <= D; i++) {
                totalCats += p;
                p *= n_hat;
            }
        }
        __int128 workersCount = (__int128)W;
        __int128 notWorking128 = totalCats - workersCount;

        // Compute sumHeight
        __int128 sumH = 0;
        __int128 term = (__int128)H; // i=0
        for (int i = 0; i <= D; i++) {
            sumH += term;
            if (i == D) break;
            term = term * (__int128)n_hat / (__int128)(n_hat + 1);
        }

        auto print128 = [&]( __int128 v ) {
            if (v == 0) { cout << 0; return; }
            if (v < 0) { cout << '-'; v = -v; }
            string s;
            while (v > 0) {
                int digit = (int)(v % 10);
                s.push_back('0' + digit);
                v /= 10;
            }
            reverse(s.begin(), s.end());
            cout << s;
        };

        print128(notWorking128);
        cout << " ";
        print128(sumH);
        cout << "\n";
    }
    return 0;
}