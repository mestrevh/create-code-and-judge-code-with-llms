/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, r, sz;
    DSU(int n=0){ init(n); }
    void init(int n){
        p.resize(n);
        r.assign(n,0);
        sz.assign(n,1);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x){
        while(p[x]!=x){
            p[x]=p[p[x]];
            x=p[x];
        }
        return x;
    }
    bool unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return false;
        if(r[a]<r[b]) swap(a,b);
        p[b]=a;
        sz[a]+=sz[b];
        if(r[a]==r[b]) r[a]++;
        return true;
    }
};

static bool readInt(istream& in, long long &out){
    out = 0;
    int c;
    do{
        if(!in.get((char&)c)) return false;
    }while(isspace(c));
    bool neg=false;
    if(c=='-'){ neg=true; if(!in.get((char&)c)) return false; }
    while(true){
        if(c==EOF) break;
        if(!isdigit(c)) { in.unget(); break; }
        out = out*10 + (c-'0');
        if(!in.get((char&)c)) break;
    }
    if(neg) out = -out;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int C;
    if(!(cin >> C)) return 0;

    for(int tc=1; tc<=C; tc++){
        int P;
        cin >> P;
        int N;
        cin >> N;

        DSU dsu(P);

        for(int i=0;i<N;i++){
            int X,Y;
            cin >> X >> Y;
            dsu.unite(X,Y);
        }

        unordered_map<int,int> count;
        count.reserve((size_t)P*2);

        for(int i=0;i<P;i++){
            int root = dsu.find(i);
            count[root]++;
        }

        int D = (int)count.size();
        int M = 0;
        for(auto &kv: count) M = max(M, kv.second);

        cout << "caso " << tc << ": " << D << " " << M << "\n";

        string line;
        if(tc != C){
            streampos pos = cin.tellg();
            if(!cin.eof()){
                getline(cin, line);
            }
        }
    }
    return 0;
}