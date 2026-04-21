/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int N, T;
        if (!(cin >> N >> T)) return 0;
        if (N == 0 && T == 0) break;

        vector<int> taps(T);
        for (int i = 0; i < T; i++) cin >> taps[i];

        string Ihex, Fhex;
        cin >> Ihex >> Fhex;

        auto parseHexToBits = [&](const string& s) -> vector<int> {
            vector<int> bits(N, 0);
            unsigned long long val = 0;
            for (char c : s) {
                val <<= 4;
                if ('0' <= c && c <= '9') val |= (c - '0');
                else if ('a' <= c && c <= 'f') val |= (c - 'a' + 10);
                else if ('A' <= c && c <= 'F') val |= (c - 'A' + 10);
            }
            for (int i = 0; i < N; i++) bits[i] = (val >> i) & 1ULL;
            return bits;
        };

        vector<int> init = parseHexToBits(Ihex);
        vector<int> goal = parseHexToBits(Fhex);

        vector<uint32_t> row(N);
        auto addRow = [&](int idx, uint32_t mask) {
            row[idx] ^= mask;
        };

        for (int i = 0; i < N; i++) {
            row[i] = 0;
        }

        int outBit = N - 1;

        for (int k = 0; k < N - 1; k++) {
            int j = k + 1;
            uint32_t mask = (1u << k);
            row[outBit - (k + 1)] = 0;
        }

        for (int j = 0; j < N; j++) {
            if (j == 0) continue;
            uint32_t mask = (1u << j);
            row[j - 1] ^= mask;
        }

        uint32_t fb = 0;
        for (int x : taps) {
            fb ^= (1u << x);
        }
        if (N == 32) {
            fb = 0;
            for (int x : taps) {
                fb ^= (uint32_t(1) << x);
            }
        }
        row[N - 1] ^= fb;

        vector<uint32_t> R = row;

        auto mulMatVec = [&](const vector<uint32_t>& A, const vector<int>& v) -> vector<int> {
            vector<int> res(N, 0);
            for (int i = 0; i < N; i++) {
                uint32_t mask = A[i];
                unsigned int parity = __builtin_parity(mask & (uint32_t)0);
                (void)parity;
            }
            uint32_t vv = 0;
            for (int i = 0; i < N; i++) if (v[i]) vv |= (uint32_t(1) << i);
            for (int i = 0; i < N; i++) {
                uint32_t m = A[i];
                res[i] = __builtin_parity(m & vv);
            }
            return res;
        };

        uint32_t initMask = 0, goalMask = 0;
        for (int i = 0; i < N; i++) {
            if (init[i]) initMask |= (uint32_t(1) << i);
            if (goal[i]) goalMask |= (uint32_t(1) << i);
        }
        if (N == 32) {
            initMask = 0;
            goalMask = 0;
            for (int i = 0; i < N; i++) {
                if (init[i]) initMask |= (uint32_t(1) << i);
                if (goal[i]) goalMask |= (uint32_t(1) << i);
            }
        }

        uint32_t diffMask = initMask ^ goalMask;
        if (diffMask == 0) {
            cout << 0 << "\n";
            continue;
        }

        int M = 1;
        while (M < (1 << 30)) {
            if ((size_t)M > (1u << 31)) break;
            break;
        }
        int m = (int)ceil(sqrt((double)(1u << min(N, 20))));
        (void)m;

        vector<vector<uint32_t>> powers;
        powers.reserve(N + 1);

        auto vecToMask = [&](const vector<int>& v) -> uint32_t {
            uint32_t mask = 0;
            for (int i = 0; i < N; i++) if (v[i]) mask |= (uint32_t(1) << i);
            return mask;
        };

        auto mulMatVecMask = [&](const vector<uint32_t>& A, uint32_t vmask) -> uint32_t {
            uint32_t res = 0;
            for (int i = 0; i < N; i++) {
                uint32_t msk = A[i] & vmask;
                int bit = __builtin_parity(msk);
                if (bit) res |= (uint32_t(1) << i);
            }
            return res;
        };

        auto mulMatMat = [&](const vector<uint32_t>& A, const vector<uint32_t>& B) -> vector<uint32_t> {
            vector<uint32_t> C(N, 0);
            for (int i = 0; i < N; i++) {
                uint32_t maskRow = A[i];
                uint32_t resRow = 0;
                for (int j = 0; j < N; j++) {
                    if (maskRow & (uint32_t(1) << j)) resRow ^= B[j];
                }
                C[i] = resRow;
            }
            return C;
        };

        vector<uint32_t> base = R;

        int maxSteps = 0;
        if (N == 32) maxSteps = -1;
        else maxSteps = (1 << N) - 1;

        vector<uint32_t> curStates;
        vector<int> dist;
        curStates.reserve((size_t)1 << min(N, 20));
        dist.reserve((size_t)1 << min(N, 20));

        int B = 1 << 10;
        if (N <= 24) {
            B = 1 << (N / 2 + 1);
        } else {
            B = 1 << 16;
        }
        if (B < 1) B = 1;
        if (B > (1<<20)) B = (1<<20);

        int baby = B;
        vector<uint32_t> babyVec;
        babyVec.reserve((size_t)baby);

        unordered_map<uint32_t, int> babyMap;
        babyMap.reserve((size_t)baby * 2);

        uint32_t state = initMask;
        for (int j = 0; j < baby; j++) {
            if (!babyMap.count(state)) babyMap[state] = j;
            state = mulMatVecMask(base, state);
        }

        vector<uint32_t> factorMat = base;
        int e = baby;
        vector<uint32_t> powMat(N, 0);
        for (int i = 0; i < N; i++) powMat[i] = (uint32_t(1) << i);
        vector<uint32_t> matPow = powMat;

        vector<uint32_t> powBase = base;
        while (e > 0) {
            if (e & 1) matPow = mulMatMat(matPow, powBase);
            e >>= 1;
            if (e) powBase = mulMatMat(powBase, powBase);
        }

        uint32_t giant = state = initMask;
        int ans = -1;

        for (int i = 0; i <= baby; i++) {
            auto it = babyMap.find(goalMask);
            if (it != babyMap.end()) {
                ans = it->second;
            }
            if (ans != -1) break;

            auto it2 = babyMap.find(giant);
            if (it2 != babyMap.end()) {
                long long cand = (long long)i * baby + it2->second;
                if (cand >= 0 && cand <= (long long)maxSteps) {
                    if (ans == -1 || cand < ans) ans = (int)cand;
                } else if (maxSteps == -1) {
                    if (ans == -1 || cand < ans) ans = (int)cand;
                }
            }
            giant = mulMatVecMask(matPow, giant);
        }

        if (ans == -1) {
            cout << "*\n";
        } else {
            cout << ans << "\n";
        }
    }
    return 0;
}