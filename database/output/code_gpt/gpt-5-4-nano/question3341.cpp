/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        long long N;
        int S;
        cin >> N >> S;

        if (S <= 0) {
            cout << 0 << "\n";
            continue;
        }

        unsigned long long x = (unsigned long long)N;

        vector<int> digits;
        if (x == 0) digits.push_back(0);
        while (x > 0) {
            digits.push_back((int)(x % 10));
            x /= 10;
        }
        int k = (int)digits.size();

        auto make_min_ge = [&](int kdig, int useS) -> pair<unsigned long long, bool> {
            int totalS = useS;
            if (totalS < 0) return {0ULL, false};

            vector<int> cnt(10, 0);
            cnt[0] = 0;
            int remaining = totalS;

            int firstDigitMax = (kdig == 1 ? 9 : 9);

            for (int i = 0; i < 10; i++) {
                if (remaining < 0) break;
                if (i == 0) continue;
                int take = min(remaining, i);
                cnt[i] = take;
                remaining -= take;
            }
            if (remaining != 0) {
                return {0ULL, false};
            }

            vector<int> assigned(kdig, 0);

            int pos = 0;
            int carry = 0;

            for (int d = 9; d >= 1; d--) {
                while (cnt[d] > 0) {
                    if (pos >= kdig) return {0ULL, false};
                    assigned[pos++] = d;
                    cnt[d]--;
                }
            }

            int used = pos;
            while (used < kdig) {
                assigned[used++] = 0;
            }

            unsigned long long val = 0;
            for (int i = kdig - 1; i >= 0; i--) {
                val = val * 10ULL + (unsigned long long)assigned[i];
            }

            return {val, true};
        };

        auto can_make_sum_s = [&](int kdig) -> bool {
            long long maxSum = 9LL * kdig;
            return S <= maxSum;
        };

        int len = k;

        while (true) {
            if (!can_make_sum_s(len)) {
                len++;
                continue;
            }

            long long maxSum = 9LL * len;
            if (S > maxSum) {
                len++;
                continue;
            }

            vector<int> d(len, 0);
            long long rem = S;

            for (int i = 0; i < len; i++) d[i] = 0;
            for (int i = 0; i < len; i++) {
                int digit = (int)min<long long>(9, rem);
                d[i] = digit;
                rem -= digit;
                if (rem == 0) break;
            }
            for (int i = 0; i < len && rem > 0; i++) {
                int add = (int)min<long long>(9 - d[i], rem);
                d[i] += add;
                rem -= add;
            }
            if (rem != 0) {
                len++;
                continue;
            }

            vector<int> numDigits(len, 0);
            for (int i = 0; i < len; i++) numDigits[i] = d[len - 1 - i];

            unsigned long long Ncur = 0;
            {
                unsigned long long tmp = x;
                vector<int> nd;
                while (tmp > 0) {
                    nd.push_back((int)(tmp % 10ULL));
                    tmp /= 10ULL;
                }
                int curk = (int)nd.size();
                if (curk < len) {
                    Ncur = N;
                }
            }

            vector<int> original;
            unsigned long long tmpN = (unsigned long long)N;
            while (tmpN > 0) {
                original.push_back((int)(tmpN % 10ULL));
                tmpN /= 10ULL;
            }
            int curk = (int)original.size();
            vector<int> origLen(len, 0);
            for (int i = 0; i < curk; i++) origLen[i] = original[i];

            vector<int> digitsA(len, 0);
            vector<int> best(len, 0);
            bool found = false;

            long long maxDiff = (long long)0;

            function<bool(int,int,int,int)> dfs = [&](int idx, int tight, int started, int sumUsed) -> bool {
                if (idx == len) {
                    return sumUsed == S && started == 1;
                }
                int minDigit = 0;
                int maxDigit = tight ? origLen[len - 1 - idx] : 9;
                if (!tight) maxDigit = 9;

                if (started == 0) minDigit = 1;

                for (int dig = minDigit; dig <= maxDigit; dig++) {
                    int ntight = tight;
                    if (tight && dig < origLen[len - 1 - idx]) ntight = 1;
                    if (tight && dig > origLen[len - 1 - idx]) ntight = 0;

                    int nstarted = started || (dig != 0);
                    if (nstarted == 0) nstarted = 0;

                    int ns = sumUsed + dig;
                    if (ns > S) continue;

                    int remainingPos = len - (idx + 1);
                    long long minPossible = 0;
                    long long maxPossible = 9LL * remainingPos;
                    if (nstarted == 1) {
                        minPossible = 0;
                    } else {
                        minPossible = 1;
                    }

                    if (ns + minPossible > S) continue;
                    if (ns + maxPossible < S) continue;

                    digitsA[idx] = dig;
                    bool ok = dfs(idx + 1, ntight, nstarted, ns);
                    if (ok) return true;
                }
                return false;
            };

            found = false;

            function<unsigned long long(int,bool,int,long long)> buildMinGreater = [&](int pos, bool greater, int started, long long sumUsed) -> unsigned long long {
                if (pos == len) {
                    if (sumUsed == S && started == 1) return 0ULL;
                    return ULLONG_MAX;
                }
                int curIndex = len - 1 - pos;
                int bound = (len == curk) ? origLen[curIndex] : 0;

                int minD = 0;
                if (started == 0) minD = 1;

                int maxD = 9;

                if (!greater && len == curk) {
                    maxD = bound + (0);
                }

                unsigned long long bestVal = ULLONG_MAX;

                for (int dig = minD; dig <= maxD; dig++) {
                    bool nstarted = started || (dig != 0);
                    int ns = (int)(sumUsed + dig);
                    if (ns > S) continue;

                    int remainingPos = len - (pos + 1);
                    long long minPossible = 0;
                    long long maxPossible = 9LL * remainingPos;
                    if (nstarted == 0) {
                        minPossible = (remainingPos > 0 ? 1 : 0);
                    } else {
                        minPossible = 0;
                    }
                    if ((long long)ns + minPossible > S) continue;
                    if ((long long)ns + maxPossible < S) continue;

                    bool ngreater = greater;
                    if (!greater) {
                        if (len == curk) {
                            if (dig > bound) ngreater = true;
                            else if (dig < bound) ngreater = false;
                            else ngreater = false;
                        } else {
                            ngreater = true;
                        }
                    }

                    if (ngreater == false && len == curk) {
                        if (dig < bound) continue;
                    }

                    unsigned long long suffix = buildMinGreater(pos + 1, ngreater, nstarted, ns);
                    if (suffix == ULLONG_MAX) continue;

                    unsigned long long val = (unsigned long long)dig;
                    int remainingDigits = len - (pos + 1);
                    for (int i = 0; i < remainingDigits; i++) val = val * 10ULL;
                    val += suffix;

                    if (bestVal == ULLONG_MAX || val < bestVal) bestVal = val;
                }
                return bestVal;
            };

            unsigned long long ans = ULLONG_MAX;

            auto try_len = [&](int L) -> void {
                if (L < 1) return;
                long long sumNeeded = S;
                if (sumNeeded > 9LL * L) return;

                vector<int> orig;
                unsigned long long tmpN2 = (unsigned long long)N;
                while (tmpN2 > 0) {
                    orig.push_back((int)(tmpN2 % 10ULL));
                    tmpN2 /= 10ULL;
                }
                int curL = (int)orig.size();
                vector<int> origPad(L, 0);
                for (int i = 0; i < min(L, curL); i++) origPad[i] = orig[i];

                function<unsigned long long(int,bool,bool,int,long long)> rec =
                    [&](int pos, bool gt, bool started, int sumUsed, long long) -> unsigned long long {
                        if (pos == L) {
                            if (sumUsed == S && started) return 0ULL;
                            return ULLONG_MAX;
                        }
                        int idx = L - 1 - pos;
                        int bound = (L == curL ? origPad[idx] : (gt ? 9 : 0));

                        int minD = 0;
                        if (!started) minD = 1;

                        int maxD = 9;
                        if (!gt && L == curL) maxD = bound;

                        unsigned long long bestLocal = ULLONG_MAX;

                        for (int dig = minD; dig <= maxD; dig++) {
                            bool nstarted = started || (dig != 0);
                            int nsum = sumUsed + dig;
                            if (nsum > S) continue;

                            int remaining = L - (pos + 1);
                            long long minPossible = 0;
                            long long maxPossible = 9LL * remaining;
                            if (!nstarted) {
                                minPossible = (remaining > 0 ? 1 : 0);
                            }
                            if ((long long)nsum + minPossible > S) continue;
                            if ((long long)nsum + maxPossible < S) continue;

                            bool ngt = gt;
                            if (!gt && L == curL) {
                                if (dig == bound) ngt = false;
                                else ngt = (dig > bound);
                            } else if (!gt && L > curL) {
                                ngt = true;
                            }

                            if (!ngt && L == curL) {
                                if (dig < bound) continue;
                                if (dig == bound && pos == L-1) continue;
                            }

                            unsigned long long suffix = rec(pos + 1, ngt, nstarted, nsum, 0);
                            if (suffix == ULLONG_MAX) continue;

                            unsigned long long val = (unsigned long long)dig;
                            unsigned long long mul = 1ULL;
                            int remDigits = remaining;
                            for (int i = 0; i < remDigits; i++) mul *= 10ULL;
                            val = val * mul + suffix;

                            if (bestLocal == ULLONG_MAX || val < bestLocal) bestLocal = val;
                        }
                        return bestLocal;
                    };

                unsigned long long cand = rec(0, false, false, 0, 0);
                if (cand != ULLONG_MAX) ans = min(ans, cand);
            };

            bool okLen = false;
            for (int L = len; L <= len + 1; L++) {
                if (S > 9LL * L) continue;
                okLen = true;
                try_len(L);
                if (ans != ULLONG_MAX) break;
            }

            if (ans == ULLONG_MAX) {
                long long diff = 0;
                cout << diff << "\n";
            } else {
                unsigned long long diff = ans - (unsigned long long)N;
                cout << diff << "\n";
            }
        }
    }
    return 0;
}