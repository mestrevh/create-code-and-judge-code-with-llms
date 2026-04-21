/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1000000007;

int addmod(int a, int b){ a+=b; if(a>=MOD) a-=MOD; return a; }
int submod(int a, int b){ a-=b; if(a<0) a+=MOD; return a; }
int mulmod(long long a, long long b){ return int((a*b)%MOD); }

int modpow(long long a, long long e){
    long long r=1%MOD;
    a%=MOD;
    while(e>0){
        if(e&1) r=r*a%MOD;
        a=a*a%MOD;
        e>>=1;
    }
    return (int)r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    while ( (cin >> N >> Q) ){
        vector<long long> K(Q);
        for(int i=0;i<Q;i++) cin >> K[i];

        vector<long long> uniqueK = K;
        sort(uniqueK.begin(), uniqueK.end());
        uniqueK.erase(unique(uniqueK.begin(), uniqueK.end()), uniqueK.end());

        int maxNeed = 0;
        for(long long kk: uniqueK){
            long long t = (kk - 1);
            if(t < 0) t = 0;
            if(N==0) continue;
            long long add = t + 1; 
            if(add > maxNeed) {
                if(add > (long long)N+5) maxNeed = N+5;
                else maxNeed = (int)add;
            }
        }
        int M = N + 2;

        vector<int> inv(M+1, 1), inv2(M+1,1);
        for(int i=1;i<=M;i++) inv[i] = modpow(i, MOD-2);

        vector<int> fact(M+1,1), invfact(M+1,1);
        for(int i=1;i<=M;i++) fact[i] = mulmod(fact[i-1], i);
        invfact[M] = modpow(fact[M], MOD-2);
        for(int i=M;i>=1;i--) invfact[i-1] = mulmod(invfact[i], i);

        auto C = [&](int n, int r)->int{
            if(r<0 || r>n) return 0;
            return mulmod(fact[n], mulmod(invfact[r], invfact[n-r]));
        };

        vector<int> dp(M+1,0);
        dp[0]=1;
        for(int m=1;m<=N;m++){
            long long sum = 0;
            for(int t=1;t<=m;t++){
                sum += 1LL * C(m-1, t-1);
                if(sum >= (1LL<<62)) sum %= MOD;
            }
            dp[m] = int(sum%MOD);
        }

        vector<int> ans(Q,0);
        for(int idx=0; idx<Q; idx++){
            long long Kval = K[idx];
            if(N==1){
                ans[idx]=1%MOD;
                continue;
            }
            if(Kval<=0){
                ans[idx]=0;
                continue;
            }
            int m = N;
            int k = (int)min<long long>(Kval, (long long)N+1);
            vector<int> coeff(m+1,0);

            coeff[0] = 1;
            for(int i=1;i<=m;i++){
                coeff[i] = dp[i];
            }

            long long x = Kval;
            long long y = x-1;
            long long res = 0;
            long long p = 1;
            vector<long long> factp(m+1,1);
            vector<long long> combs(m+1,1);

            for(int i=0;i<=m;i++){
                if(i==0) p = 1;
                else p = p * ((y + (long long)i)%MOD) % MOD;
            }
            vector<long long> powX(m+1,1);
            long long Xmod = (x%MOD+MOD)%MOD;
            for(int i=1;i<=m;i++) powX[i] = powX[i-1]*Xmod%MOD;

            res=0;
            vector<long long> s(m+1,0);
            s[0]=1;
            for(int i=1;i<=m;i++){
                s[i] = (s[i-1]* (y%MOD) + ( (long long)dp[i] * powX[i-1] % MOD ) ) % MOD;
            }

            ans[idx] = int(s[m]%MOD);
        }

        for(int i=0;i<Q;i++){
            cout << ans[i] % MOD << (i+1==Q?'\n':' ');
        }
    }
    return 0;
}