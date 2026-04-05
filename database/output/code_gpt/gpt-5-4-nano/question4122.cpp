/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    vector<int> A(N);
    int maxA = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        maxA = max(maxA, A[i]);
    }
    int Q;
    cin >> Q;
    vector<int> Ks(Q);
    int maxK = 0;
    for (int i = 0; i < Q; i++) {
        cin >> Ks[i];
        maxK = max(maxK, Ks[i]);
    }

    vector<long long> answers(Q, 0);

    const int TH = 450;
    unordered_map<int, vector<int>> freqByMod; 
    freqByMod.reserve(Q * 2);

    unordered_map<int, vector<int>> countByK;
    countByK.reserve(Q * 2);

    vector<int> uniqKs;
    uniqKs.reserve(Q);
    {
        unordered_set<int> s;
        s.reserve(Q * 2);
        for (int k : Ks) {
            if (!s.count(k)) {
                s.insert(k);
                uniqKs.push_back(k);
            }
        }
    }

    vector<char> isHeavy(uniqKs.size(), 0);
    int heavyLimit = TH;

    unordered_set<int> heavySet;
    heavySet.reserve(uniqKs.size() * 2);
    for (int k : uniqKs) if (k > heavyLimit) heavySet.insert(k);

    for (int idx = 0; idx < Q; idx++) {
        int K = Ks[idx];
        if (K > heavyLimit) {
            int k = K;
            vector<int> cnt(k, 0);
            for (int x : A) cnt[x % k]++;
            long long ans = 0;
            int half = (k % 2 == 0) ? k / 2 : -1;
            for (int r = 0; r < k; r++) {
                int s = (k - r) % k;
                if (r < s) ans += 1LL * cnt[r] * cnt[s];
                else if (r == s) {
                    ans += 1LL * cnt[r] * (cnt[r] - 1) / 2;
                }
            }
            answers[idx] = ans;
        }
    }

    for (int idx = 0; idx < Q; idx++) {
        int K = Ks[idx];
        if (K <= heavyLimit) {
            int k = K;
            vector<int> cnt(k, 0);
            for (int x : A) cnt[x % k]++;
            long long ans = 0;
            for (int r = 0; r < k; r++) {
                int s = (k - r) % k;
                if (r < s) ans += 1LL * cnt[r] * cnt[s];
                else if (r == s) ans += 1LL * cnt[r] * (cnt[r] - 1) / 2;
            }
            answers[idx] = ans;
        }
    }

    for (int i = 0; i < Q; i++) {
        cout << answers[i] << "\n";
    }
    return 0;
}