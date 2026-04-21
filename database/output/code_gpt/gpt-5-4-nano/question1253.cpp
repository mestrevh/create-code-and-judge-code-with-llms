/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static inline uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15ULL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
}

struct TableA {
    int M;
    vector<int> tab;
    int sz;
    int maxM;
    long long comps;

    TableA(int m=0): M(m), tab(m, -1), sz(0), maxM(0), comps(0) {}

    void init(int m) {
        M = m;
        tab.assign(M, -1);
        sz = 0;
        maxM = 0;
        comps = 0;
    }

    void rehashIfNeeded() {
        double L = (double)sz / (double)M;
        if (L < 0.75) return;
        int newM = 2*M;
        vector<vector<int>> items(M);
        for(int i=0;i<M;i++){
            if(tab[i]!=-1) items[i].push_back(tab[i]);
        }
        vector<int> newTab(newM, -1);
        vector<vector<int>> lists(newM);
        for(int i=0;i<M;i++){
            if(tab[i]!=-1){
                int val = tab[i];
                int idx = val % newM;
                lists[idx].push_back(val);
            }
        }
        for(int i=0;i<newM;i++){
            if(!lists[i].empty()) newTab[i]=lists[i].front();
        }
        M = newM;
        tab.swap(newTab);
    }

    void insert(int k) {
        if(sz + 1 > N_MAX) {}
        rehashIfNeeded();
        int idx = k % M;
        tab[idx] = k;
        sz++;
    }

    bool find(int k) {
        int idx = k % M;
        comps++;
        return tab[idx]==k;
    }
};

struct TableB {
    int M;
    vector<vector<int>> tab;
    int sz;
    long long comps;

    TableB(int m=0): M(m), tab(m), sz(0), comps(0) {}

    void init(int m) {
        M = m;
        tab.assign(M, {});
        sz = 0;
        comps = 0;
    }

    void rehashIfNeeded() {
        double L = (double)sz / (double)M;
        if (L < 0.75) return;
        int newM = 2*M;
        vector<vector<int>> newTab(newM);
        for(int i=0;i<M;i++){
            for(int v: tab[i]){
                int idx = v % newM;
                newTab[idx].push_back(v);
            }
        }
        for(int i=0;i<newM;i++){
            if(!newTab[i].empty()) sort(newTab[i].begin(), newTab[i].end());
        }
        tab.swap(newTab);
        M = newM;
    }

    void insert(int k) {
        rehashIfNeeded();
        int idx = k % M;
        auto &bucket = tab[idx];
        bucket.insert(lower_bound(bucket.begin(), bucket.end(), k), k);
        sz++;
    }

    bool find(int k) {
        int idx = k % M;
        auto &bucket = tab[idx];
        int lo = 0, hi = (int)bucket.size() - 1;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            comps++;
            if(bucket[mid] == k) return true;
            if(bucket[mid] < k) lo = mid + 1;
            else hi = mid - 1;
        }
        return false;
    }
};

struct TableC {
    int M;
    vector<vector<int>> tab;
    int sz;
    long long comps;

    TableC(int m=0): M(m), tab(m), sz(0), comps(0) {}

    void init(int m) {
        M = m;
        tab.assign(M, {});
        sz = 0;
        comps = 0;
    }

    inline int h0(int k, int m) { return k % m; }
    inline int h1(int k, int m) { return 2 * (k % (m/2)) + 1; }

    void rehashIfNeeded() {
        double L = (double)sz / (double)M;
        if (L < 0.75) return;
        int newM = 2*M;
        vector<vector<int>> newTab(newM);
        for(int i=0;i<M;i++){
            for(int v: tab[i]){
                int idx0 = h0(v, newM);
                int idx1 = h1(v, newM);
                int idx = (int)newTab[idx0].size() ? idx0 : idx1;
                if(newTab[idx0].size()==0) idx = idx0;
                else idx = idx1;
                newTab[idx].push_back(v);
            }
        }
        tab.swap(newTab);
        M = newM;
    }

    void insert(int k) {
        rehashIfNeeded();
        int idx0 = h0(k, M);
        int idx1 = h1(k, M);
        if(tab[idx0].empty()) tab[idx0].push_back(k);
        else if(tab[idx1].empty()) tab[idx1].push_back(k);
        else tab[idx0].push_back(k);
        sz++;
    }

    bool find(int k) {
        int idx0 = h0(k, M);
        for(int v: tab[idx0]) { comps++; if(v==k) return true; }
        int idx1 = h1(k, M);
        for(int v: tab[idx1]) { comps++; if(v==k) return true; }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if(!(cin >> T)) return 0;
    for(int tc=0; tc<T; tc++){
        long long K;
        int M, N, Q;
        cin >> K >> M >> N >> Q;

        vector<int> s(N);
        for(int i=0;i<N;i++) cin >> s[i];

        vector<int> v(Q);
        for(int i=0;i<Q;i++) cin >> v[i];

        TableA A(M);
        TableB B(M);
        TableC C(M);
        A.init(M);
        B.init(M);
        C.init(M);

        for(int x: s){
            A.insert(x);
            B.insert(x);
            C.insert(x);
        }

        long long pen = 0;
        long long compA=0, compB=0, compC=0;

        for(int x: v){
            bool fa = A.find(x);
            bool fb = B.find(x);
            bool fc = C.find(x);
            compA += A.comps; A.comps = 0;
            compB += B.comps; B.comps = 0;
            compC += C.comps; C.comps = 0;
            if(!fa && !fb && !fc) pen++;
        }

        cout << "caso " << tc << ": " << pen << " " << compA << " " << compB << " " << compC << "\n";
        string blank;
        getline(cin, blank);
        getline(cin, blank);
    }
    return 0;
}