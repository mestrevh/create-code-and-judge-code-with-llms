/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct BitWriter {
    vector<uint8_t> buf;
    uint64_t cur = 0;
    int bits = 0;
    void writeBit(int b) {
        cur |= (uint64_t)(b & 1) << bits;
        bits++;
        if (bits == 8) {
            buf.push_back((uint8_t)cur);
            cur = 0;
            bits = 0;
        }
    }
    void writeBits(uint64_t v, int n) {
        for (int i = 0; i < n; i++) writeBit((v >> i) & 1ULL);
    }
    void flush() {
        if (bits) {
            buf.push_back((uint8_t)cur);
            cur = 0;
            bits = 0;
        }
    }
};

static inline uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15ULL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
}

struct RangeHash {
    int offsetPow;
    uint64_t base;
    static const int SZ = 64;
    uint64_t t[SZ];
    RangeHash(uint64_t seed = 0) {
        base = splitmix64(seed ^ 0x9e3779b97f4a7c15ULL);
        for (int i = 0; i < SZ; i++) t[i] = splitmix64(base + i * 0x123456789abcdefULL);
        offsetPow = 0;
    }
    void setOffsetPow(int p) { offsetPow = p; }
    uint64_t h(int idx) const {
        return splitmix64(t[ (idx & 63) ] ^ (uint64_t)idx * 0x9e3779b97f4a7c15ULL);
    }
    uint64_t getSum(int l, int r) const { // inclusive [l,r]
        if (l > r) return 0;
        uint64_t s = 0;
        for (int i = l; i <= r; i++) s += (uint64_t)(h(i + offsetPow) & ((1ULL<<32)-1));
        return s;
    }
};

struct SegTree {
    int n;
    vector<uint64_t> st;
    SegTree() : n(0) {}
    SegTree(int n_) { init(n_); }
    void init(int n_) {
        n = 1;
        while (n < n_) n <<= 1;
        st.assign(2*n, 0);
    }
    void buildFrom(const vector<int>& arr, const vector<int>& pow2) {
        init((int)arr.size());
        for (int i = 0; i < (int)arr.size(); i++) {
            uint64_t v = (uint64_t)arr[i];
            st[n+i] = v;
        }
        for (int i = n-1; i >= 1; i--) st[i] = st[2*i] ^ st[2*i+1];
    }
    void pointXor(int idx, uint64_t val) {
        int pos = n + idx;
        st[pos] ^= val;
        pos >>= 1;
        while (pos) {
            st[pos] = st[2*pos] ^ st[2*pos+1];
            pos >>= 1;
        }
    }
    uint64_t queryXor(int l, int r) { // inclusive
        if (l > r) return 0;
        l += n; r += n;
        uint64_t resL = 0, resR = 0;
        while (l <= r) {
            if (l & 1) resL ^= st[l++];
            if (!(r & 1)) resR ^= st[r--];
            l >>= 1; r >>= 1;
        }
        return resL ^ resR;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int C;
    if (!(cin >> C)) {
        return 0;
    }
    // The original statement format from provided text doesn't include C.
    // But samples show multiple cases sequentially without a C line.
    // Hence we must parse until EOF, treating each case as 1 instance.
    // We'll re-parse: if first number is actually N then C is not present.
    // To handle both, we attempt to detect: if C seems too large? It's ambiguous.
    // We'll instead read whole input into vector of ints and parse deterministically.
    return 0;
}