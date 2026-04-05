/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Course {
    string name;
    vector<int> pre;
};

static int cmpLex(const string& a, const string& b) {
    auto orderChar = [](char c)->int{
        if ('0'<=c && c<='9') return c-'0';
        return 10 + (c-'A');
    };
    size_t i=0, n=a.size(), m=b.size();
    size_t k=min(n,m);
    for(; i<k; i++){
        int oa=orderChar(a[i]), ob=orderChar(b[i]);
        if(oa<ob) return -1;
        if(oa>ob) return 1;
    }
    if(n==m) return 0;
    if(n<m){
        return -1;
    } else return 1;
}

static bool lexLess(const string& a, const string& b){
    return cmpLex(a,b) < 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    while ( (cin >> N >> M) ) {
        if(N==0 && M==0) break;

        vector<Course> adv(N);
        unordered_map<string,int> id;
        id.reserve(512);

        vector<int> priority; priority.reserve(512);
        vector<string> names; names.reserve(512);

        auto getId = [&](const string& s)->int{
            auto it = id.find(s);
            if(it!=id.end()) return it->second;
            int nid = (int)names.size();
            id[s]=nid;
            names.push_back(s);
            priority.push_back(nid);
            return nid;
        };

        for(int i=0;i<N;i++){
            string advName; int K;
            cin >> advName >> K;
            int aId = getId(advName);
            adv[i].name = advName;
            adv[i].pre.clear();
            adv[i].pre.reserve(K);
            for(int j=0;j<K;j++){
                string p; cin >> p;
                int pId = getId(p);
                adv[i].pre.push_back(pId);
            }
        }

        int V = (int)names.size();
        vector<int> isAdvanced(V,0);
        for(int i=0;i<N;i++){
            isAdvanced[id[adv[i].name]] = 1;
        }

        vector<int> outdeg(V,0);
        vector<vector<int>> adj(V);
        vector<int> indeg(V,0);

        for(int i=0;i<N;i++){
            int aId = id[adv[i].name];
            for(int p: adv[i].pre){
                adj[p].push_back(aId);
                indeg[aId]++;
            }
        }

        vector<int> isBasic(V,0);
        for(int u=0;u<V;u++){
            for(int v: adj[u]) {
                (void)v;
            }
        }
        for(int v=0;v<V;v++){
            if(!isAdvanced[v] && indeg[v]>0){
                isBasic[v]=1;
            }
        }
        for(int v=0;v<V;v++){
            if(!isAdvanced[v] && indeg[v]==0){
                isBasic[v]=1;
            }
        }
        bool hasAnyPre = false;
        for(int v=0;v<V;v++) if(indeg[v]>0) hasAnyPre=true;
        if(hasAnyPre){
            for(int v=0;v<V;v++){
                if(!isAdvanced[v] && indeg[v]==0){
                    isBasic[v]=1;
                }
            }
        }

        vector<int> required(V,0);
        int requiredCount=0;
        for(int v=0;v<V;v++){
            if(isAdvanced[v] || (!isAdvanced[v] && (indeg[v]==0 || true))){
                if(!isAdvanced[v]){
                    bool appearsAsPre=false;
                    for(int u=0;u<V && !appearsAsPre;u++){
                        for(int w: adj[u]){
                            if(w==v){appearsAsPre=true;break;}
                        }
                    }
                    if(appearsAsPre){
                        required[v]=1;
                        requiredCount++;
                    }
                } else {
                    required[v]=1;
                    requiredCount++;
                }
            }
        }
        if(requiredCount==0){
            for(int v=0;v<V;v++){
                if(isAdvanced[v] || (!isAdvanced[v] && indeg[v]==0)) { required[v]=1; requiredCount++; }
            }
        }

        vector<int> indegReq = indeg;
        for(int v=0;v<V;v++){
            if(!required[v]){ indegReq[v]=0; }
        }
        vector<vector<int>> prereqList(V);
        for(int i=0;i<N;i++){
            int aId = id[adv[i].name];
            if(!required[aId]) continue;
            prereqList[aId]=adv[i].pre;
        }

        vector<int> done(V,0);
        int completed=0;

        vector<int> semCountList;
        vector<vector<int>> semesters;

        struct Cand{
            int v;
        };
        vector<int> available;
        available.reserve(V);

        auto updateAvailable = [&](){
            available.clear();
            for(int v=0;v<V;v++){
                if(required[v] && !done[v] && indegReq[v]==0) available.push_back(v);
            }
        };

        updateAvailable();

        while(completed < requiredCount){
            updateAvailable();
            vector<int> pick;
            if((int)available.size() > M){
                vector<int> best;
                best.reserve(M);
                vector<pair<int,int>> pr;
                pr.reserve(available.size());
                for(int v: available){
                    pr.push_back({priority[v], v});
                }
                sort(pr.begin(), pr.end(), [](auto &x, auto &y){
                    return x.first > y.first;
                });
                best.clear();
                for(int i=0;i<M;i++) best.push_back(pr[i].second);
                pick = best;
            } else {
                pick = available;
            }

            vector<int> used = pick;
            sort(used.begin(), used.end(), [&](int a, int b){
                return lexLess(names[a], names[b]);
            });

            for(int v: pick){
                done[v]=1;
                completed++;
                for(int w: adj[v]){
                    if(required[w]){
                        indegReq[w]--;
                    }
                }
            }

            semesters.push_back(used);
        }

        cout << "Formatura em " << semesters.size() << " semestres\n";
        for(auto &sem : semesters){
            cout << "Semestre " << (&sem - &semesters[0] + 1);
        }
        for(size_t s=0;s<semesters.size();s++){
            cout << "Semestre " << (s+1) << " : ";
            for(size_t i=0;i<semesters[s].size();i++){
                if(i) cout << ' ';
                cout << names[semesters[s][i]];
            }
            cout << "\n";
        }
    }
    return 0;
}