/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static const int MOD = 998244353;

int addmod(int a, int b){ a += b; if(a>=MOD) a-=MOD; return a; }
int submod(int a, int b){ a -= b; if(a<0) a+=MOD; return a; }
int mulmod(long long a, long long b){ return int((a*b)%MOD); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, C;
    if(!(cin >> N >> M >> C)) return 0;
    vector<int> L(M), R(M);
    for(int i=0;i<M;i++){
        cin >> L[i] >> R[i];
    }

    vector<int> eventsStart(N+2), eventsEnd(N+2);
    for(int i=0;i<M;i++){
        eventsStart[L[i]]++;
        eventsEnd[R[i]]++;
    }

    vector<int> fact(N+1), invfact(N+1);
    fact[0]=1;
    for(int i=1;i<=N;i++) fact[i]=mulmod(fact[i-1], i);
    auto modpow = [&](long long a, long long e){
        long long r=1%MOD;
        a%=MOD;
        while(e>0){
            if(e&1) r=r*a%MOD;
            a=a*a%MOD;
            e>>=1;
        }
        return int(r);
    };
    invfact[N]=modpow(fact[N], MOD-2);
    for(int i=N;i>=1;i--) invfact[i-1]=mulmod(invfact[i], i);

    auto nCr = [&](int n, int r)->int{
        if(r<0 || r>n) return 0;
        return mulmod(fact[n], mulmod(invfact[r], invfact[n-r]));
    };

    vector<int> dp0(N+1,0), dp1(N+1,0);
    dp0[0]=1;

    int active = 0;
    for(int x=1;x<=N;x++){
        active += eventsStart[x];
        int totalIntervalsCoveringX = active;
        int ending = eventsEnd[x];
        int stay = totalIntervalsCoveringX - ending;
        vector<int> ndp0(N+1,0), ndp1(N+1,0);

        for(int k=0;k<=N;k++){
            if(dp0[k]){
                int ways = dp0[k];
                for(int s=0;s<=k;s++){
                    (void)s;
                }
            }
        }

        for(int k=0;k<=x-1;k++){
            (void)k;
        }

        for(int k=0;k<=N;k++){
            if(dp0[k]){
                long long ways = dp0[k];
                if(active>0){
                    ndp1[k+1] = addmod(ndp1[k+1], int(mulmod(ways, C)));
                    ndp0[k] = addmod(ndp0[k], int(mulmod(ways, C - 1)));
                }else{
                    ndp0[k] = addmod(ndp0[k], int(ways));
                }
            }
            if(dp1[k]){
                long long ways = dp1[k];
                ndp1[k] = addmod(ndp1[k], int(ways));
            }
        }

        dp0.swap(ndp0);
        dp1.swap(ndp1);

        active -= ending;
        dp0[0]=dp0[0];
    }

    int ans = 0;
    for(int i=0;i<=N;i++){
        ans = addmod(ans, dp0[i]);
        ans = addmod(ans, dp1[i]);
    }
    cout << ans % MOD << "\n";
    return 0;
}