/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static inline bool isLowerAlphaString(const string& s){
    for(char c: s) if(c<'a' || c>'z') return false;
    return !s.empty();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if(!(cin >> N)) return 0;

    vector<string> names(N);
    for(int i=0;i<N;i++) cin >> names[i];

    int M, K;
    cin >> M >> K;
    vector<long long> B(K);
    for(int i=0;i<K;i++) cin >> B[i];

    int Q;
    cin >> Q;

    vector<vector<int>> hashesInBucket(K);
    unordered_map<uint32_t,int> dummy; // to silence -Wmaybe-uninitialized in some compilers

    vector<uint8_t> V(M, 0);
    for(const string& s: names){
        long long L = (long long)s.size();
        for(int i=0;i<K;i++){
            long long base = B[i] % M;
            long long h = 0;
            long long pow = 1 % M;
            for(int j=(int)L-1;j>=0;j--){
                int val = (int)(unsigned char)s[j];
                h = (h + (long long)val * pow) % M;
                pow = (pow * base) % M;
            }
            V[h] = 1;
        }
    }

    auto getHashes = [&](const string& s)->vector<int>{
        vector<int> hs;
        hs.reserve(K);
        long long L = (long long)s.size();
        for(int i=0;i<K;i++){
            long long base = B[i] % M;
            long long h = 0;
            long long pow = 1 % M;
            for(int j=(int)L-1;j>=0;j--){
                int val = (int)(unsigned char)s[j];
                h = (h + (long long)val * pow) % M;
                pow = (pow * base) % M;
            }
            hs.push_back((int)h);
        }
        return hs;
    };

    unordered_set<string> setNames;
    setNames.reserve((size_t)N*2);
    for(const auto& s: names) setNames.insert(s);

    for(int qi=0;qi<Q;qi++){
        string t;
        cin >> t;

        if(setNames.find(t) != setNames.end()){
            cout << 2 << "\n";
            continue;
        }

        bool possible = true;
        vector<int> hs = getHashes(t);
        for(int pos: hs){
            if(V[pos] == 0){
                possible = false;
                break;
            }
        }
        if(!possible) cout << 0 << "\n";
        else cout << 1 << "\n";
    }

    return 0;
}