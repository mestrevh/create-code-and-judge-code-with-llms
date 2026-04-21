/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeL {
    int n;
    vector<int> left, mid;
    TreeL(int n=0): n(n), left(n+1,0), mid(n+1,0) {}
};

struct TreeR {
    int n;
    vector<int> mid, right;
    TreeR(int n=0): n(n), mid(n+1,0), right(n+1,0) {}
};

struct Key {
    int a,b;
    bool operator==(Key const& o) const { return a==o.a && b==o.b; }
};

struct KeyHash {
    size_t operator()(Key const& k) const {
        return (size_t)k.a * 1000003u + (size_t)k.b;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if(!(cin >> N)) return 0;

    TreeL C(N);
    for(int i=0;i<N;i++){
        int I,L,K;
        cin >> I >> L >> K;
        C.left[I]=L;
        C.mid[I]=K;
    }

    int M;
    cin >> M;
    TreeR D(M);
    for(int i=0;i<M;i++){
        int P,Q,R;
        cin >> P >> Q >> R;
        D.mid[P]=Q;
        D.right[P]=R;
    }

    vector<int> sizeC(N+1,0), sizeD(M+1,0);
    vector<char> visC(N+1,0), visD(M+1,0);

    function<int(int)> dfsC = [&](int u)->int{
        if(u==0) return 0;
        if(visC[u]) return sizeC[u];
        visC[u]=1;
        sizeC[u]=1 + dfsC(C.left[u]) + dfsC(C.mid[u]);
        return sizeC[u];
    };
    function<int(int)> dfsD = [&](int u)->int{
        if(u==0) return 0;
        if(visD[u]) return sizeD[u];
        visD[u]=1;
        sizeD[u]=1 + dfsD(D.mid[u]) + dfsD(D.right[u]);
        return sizeD[u];
    };

    dfsC(1);
    dfsD(1);

    unordered_map<Key,int,KeyHash> memo;
    memo.reserve((size_t)(N+M)*8);

    function<int(int,int)> solve = [&](int a,int b)->int{
        if(a==0 && b==0) return 0;
        if(a==0) return sizeD[b];
        if(b==0) return sizeC[a];

        Key key{a,b};
        auto it = memo.find(key);
        if(it!=memo.end()) return it->second;

        int caL = C.left[a];
        int caM = C.mid[a];
        int dbM = D.mid[b];
        int dbR = D.right[b];

        vector<array<int,3>> cases = {
            array<int,3>{1,2,3},
        };

        int best = INT_MAX;

        auto upd = [&](int cost){ if(cost<best) best=cost; };

        int A1 = caL, A2 = caM;
        int B1 = dbM, B2 = dbR;

        int option1 = 1 + solve(A1,B1) + solve(A2,B2);
        int option2 = 1 + solve(A1,B2) + solve(A2,B1);
        int option3 = 1 + solve(A1,0) + solve(A2,B1) + solve(0,B2);
        int option4 = 1 + solve(A1,B1) + solve(A2,0) + solve(0,B2);
        int option5 = 1 + solve(A1,0) + solve(A2,B2) + solve(0,B1);
        int option6 = 1 + solve(A1,B2) + solve(A2,0) + solve(0,B1);
        int option7 = 1 + solve(A1,0) + solve(A2,0) + solve(0,B1) + solve(0,B2);

        upd(option1);
        upd(option2);
        upd(option3);
        upd(option4);
        upd(option5);
        upd(option6);
        upd(option7);

        memo.emplace(key,best);
        return best;
    };

    int ans = INT_MAX;

    ans = min(ans, 1 + ( (C.left[1]?0:0) ) ); 

    int rootC = 1;
    int rootD = 1;

    int base1 = solve(rootC, rootD);
    ans = min(ans, base1);

    vector<int> matchVariants;

    auto takeMin = [&](int x){ ans=min(ans,x); };

    takeMin(solve(rootC, 0) + sizeD[rootD]); 
    takeMin(solve(0, rootD) + sizeC[rootC]);

    ans = min(ans, solve(rootC, rootD));

    cout << ans << "\n";
    return 0;
}