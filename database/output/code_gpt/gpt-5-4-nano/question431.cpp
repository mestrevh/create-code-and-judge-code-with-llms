/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static inline vector<int> kmpPrefix(const string& p){
    vector<int> pi(p.size(),0);
    for(size_t i=1;i<p.size();i++){
        int j=pi[i-1];
        while(j>0 && p[i]!=p[j]) j=pi[j-1];
        if(p[i]==p[j]) j++;
        pi[i]=j;
    }
    return pi;
}

static inline vector<vector<int>> buildTransition(const vector<string>& words, int maxLen){
    vector<int> allIdx(words.size());
    (void)allIdx;
    int M = words.size();
    vector<vector<int>> nxt(maxLen+1, vector<int>(2,-1));
    return nxt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N1, N2;
    while ( (cin >> N1 >> N2) ){
        vector<string> A(N1), B(N2);
        for(int i=0;i<N1;i++) cin >> A[i];
        for(int i=0;i<N2;i++) cin >> B[i];

        auto solveGroup = [&](const vector<string>& W)->vector<long long>{
            int m = (int)W.size();
            int maxL = 40;
            vector<int> lens(m);
            int minL = 1e9;
            for(int i=0;i<m;i++){
                lens[i] = (int)W[i].size();
                minL = min(minL, lens[i]);
            }
            int Lmax = min(maxL, 40);
            int maxK = 40; 

            vector<long long> dp(maxK+1, -1), ndp;
            dp[0] = 0;
            vector<string> patterns;
            patterns.reserve(m);
            for(auto &s: W) patterns.push_back(s);

            vector<array<long long,2>> ansDummy; 
            (void)ansDummy;
            vector<int> allLens = lens;

            vector<long long> ways(maxK+1,0);
            ways[0]=1;
            queue<int> q;

            vector<int> reachableLen(maxL+1,0);
            reachableLen[0]=1;
            for(int cur=0;cur<=maxL;cur++){
                if(!reachableLen[cur]) continue;
                for(int i=0;i<m;i++){
                    int nl = cur + lens[i];
                    if(nl<=maxL) reachableLen[nl]=1;
                }
            }

            return ways;
        };

        vector<string> allWordsA = A, allWordsB = B;

        const int LIMIT_LEN = 40;

        auto buildSet = [&](const vector<string>& W, int maxLen){
            vector<pair<string,int>> res;
            int m = (int)W.size();
            vector<string> cur;
            cur.reserve(1);
            res.reserve(1024);
            unordered_set<string> seen;
            seen.reserve(200000);
            seen.max_load_factor(0.7f);

            for(auto &s: W){
                if((int)s.size()<=maxLen){
                    if(seen.insert(s).second) res.push_back({s,0});
                }
            }

            bool changed = true;
            while(changed){
                changed = false;
                vector<string> snapshot;
                snapshot.reserve(seen.size());
                for(auto &x: seen) snapshot.push_back(x);

                for(auto &x: snapshot){
                    for(auto &t: W){
                        int nl = (int)x.size() + (int)t.size();
                        if(nl > maxLen) continue;
                        string y = x + t;
                        if(seen.insert(y).second){
                            changed = true;
                            res.push_back({y,0});
                        }
                    }
                }
                if(seen.size() > 200000) break;
            }

            vector<string> out;
            out.reserve(seen.size());
            for(auto &x: seen) out.push_back(x);
            return out;
        };

        auto buildAllConcats = [&](const vector<string>& W, int maxLen)->unordered_set<string>{
            unordered_set<string> seen;
            seen.reserve(200000);
            seen.max_load_factor(0.7f);

            for(auto &s: W) if((int)s.size()<=maxLen) seen.insert(s);

            queue<string> q;
            for(auto &s: W) if((int)s.size()<=maxLen) q.push(s);

            vector<int> lens;
            for(auto &s: W) lens.push_back((int)s.size());
            vector<string> sorted = W;

            while(!q.empty()){
                string cur = q.front(); q.pop();
                int curL = (int)cur.size();
                if(curL > maxLen) continue;
                for(auto &w: sorted){
                    int nl = curL + (int)w.size();
                    if(nl > maxLen) continue;
                    string nxt = cur + w;
                    if(seen.insert(nxt).second){
                        q.push(nxt);
                        if(seen.size() > 250000) break;
                    }
                }
                if(seen.size() > 250000) break;
            }
            return seen;
        };

        auto SA = buildAllConcats(allWordsA, LIMIT_LEN);
        auto SB = buildAllConcats(allWordsB, LIMIT_LEN);

        bool ok = false;
        if(!SA.empty() && !SB.empty()){
            if(SA.size() > SB.size()){
                for(auto &s: SB){
                    if(SA.find(s)!=SA.end()){ ok=true; break; }
                }
            }else{
                for(auto &s: SA){
                    if(SB.find(s)!=SB.end()){ ok=true; break; }
                }
            }
        }

        cout << (ok ? "S\n" : "N\n");
    }

    return 0;
}