/*
Código criado pelo models/gemini-3.1-flash-lite-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

struct BloomFilter {
    int M, K;
    vector<int> B;
    vector<bool> V;
    vector<string> S;

    BloomFilter(int N, int M, int K) : M(M), K(K), V(M, false) {
        B.resize(K);
        S.resize(N);
    }

    void add(const string& s) {
        for (int i = 0; i < K; ++i) {
            ll h = 0;
            ll p = 1;
            for (char c : s) {
                h = (h + (ll)c * p) % M;
                p = (p * B[i]) % M;
            }
            V[h] = true;
        }
    }

    int query(const string& s, const vector<string>& sorted_users) {
        bool all_ones = true;
        for (int i = 0; i < K; ++i) {
            ll h = 0;
            ll p = 1;
            for (char c : s) {
                h = (h + (ll)c * p) % M;
                p = (p * B[i]) % M;
            }
            if (!V[h]) {
                all_ones = false;
                break;
            }
        }

        bool exists = binary_search(sorted_users.begin(), sorted_users.end(), s);
        
        if (!all_ones) return 0;
        if (exists) return 2;
        return 1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;
    vector<string> S(N);
    for (int i = 0; i < N; ++i) cin >> S[i];

    int M, K;
    cin >> M >> K;
    BloomFilter bf(N, M, K);
    for (int i = 0; i < K; ++i) cin >> bf.B[i];

    for (int i = 0; i < N; ++i) bf.add(S[i]);

    int Q;
    cin >> Q;
    while (Q--) {
        string T;
        cin >> T;
        cout << bf.query(T, S) << "\n";
    }

    return 0;
}