/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Mat {
    long long a[2][2];
    Mat(bool ident=false){
        a[0][0]=a[1][1]=ident?1:0;
        a[0][1]=a[1][0]=0;
    }
};

static inline Mat mul(const Mat& x, const Mat& y, long long mod){
    Mat r;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            __int128 v=0;
            for(int k=0;k<2;k++){
                v += (__int128)x.a[i][k]*y.a[k][j];
            }
            r.a[i][j]=(long long)(v%mod);
        }
    }
    return r;
}

static inline Mat mpow(Mat base, long long exp, long long mod){
    Mat res(true);
    while(exp>0){
        if(exp&1) res=mul(res, base, mod);
        base=mul(base, base, mod);
        exp>>=1;
    }
    return res;
}

static inline int applyFlip(int state){
    return state^1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R;
    if(!(cin>>R)) return 0;
    vector<string> S(R);
    vector<long long> F(R);
    for(int i=0;i<R;i++){
        cin>>S[i]>>F[i];
    }

    vector<int> len(R);
    for(int i=0;i<R;i++) len[i]= (int)S[i].size();

    const long long MOD = (1LL<<62); 

    auto charToBit=[&](char c)->int{ return c=='O'?1:0; }; 
    auto bitToChar=[&](int b)->char{ return b? 'O':'X'; };

    vector<string> finalStr(R);

    for(int tc=0; tc<R; tc++){
        int n = len[tc];
        vector<int> bits(n);
        for(int i=0;i<n;i++) bits[i]=charToBit(S[tc][i]);

        long long C = F[tc];

        for(long long t=1; t<=C && n<=60; t++){
            bits[0]=applyFlip(bits[0]);
            for(int i=1;i<n;i++){
                if(bits[i-1]==0){
                    bits[i]=applyFlip(bits[i]);
                }else{
                    break;
                }
            }
        }

        if(C>60){
            vector<int> cur=bits;
            vector<int> init=cur;

            vector<int> after1(n);
            {
                vector<int> temp(n);
                for(int i=0;i<n;i++) temp[i]=charToBit(S[tc][i]);
                temp[0]=applyFlip(temp[0]);
                for(int i=1;i<n;i++){
                    if(temp[i-1]==0) temp[i]=applyFlip(temp[i]);
                    else break;
                }
                after1=temp;
            }

            int period = 1;
            int limit = 200;
            vector<int> seen(n);
            (void)seen;

            vector<int> state=after1;
            int p=0;
            vector<vector<int>> states;
            states.push_back(init);
            states.push_back(after1);
            p=2;
            int maxCheck = 2*n+10;
            vector<int> seq;
            (void)seq;
            while(p<maxCheck){
                vector<int> next=state;
                next[0]=applyFlip(next[0]);
                for(int i=1;i<n;i++){
                    if(next[i-1]==0) next[i]=applyFlip(next[i]);
                    else break;
                }
                bool found=false;
                for(int j=0;j<(int)states.size();j++){
                    if(states[j]==next){ found=true; period=p-j; break; }
                }
                if(found) break;
                states.push_back(next);
                state=next;
                p++;
            }
            if(p>=maxCheck){
                period = 1;
            }

            long long idx;
            if(C==0) idx=0;
            else{
                idx = C % period;
            }

            vector<int> ans(n);
            vector<int> tempState=init;
            if(idx==0){
                ans=init;
            }else{
                vector<int> s=after1;
                if(idx==1) ans=s;
                else{
                    vector<int> x=s;
                    for(long long k=1;k<idx;k++){
                        x[0]=applyFlip(x[0]);
                        for(int i=1;i<n;i++){
                            if(x[i-1]==0) x[i]=applyFlip(x[i]);
                            else break;
                        }
                    }
                    ans=x;
                }
            }
            bits=ans;
        }

        string out;
        out.reserve(n);
        for(int i=0;i<n;i++) out.push_back(bitToChar(bits[i]));
        finalStr[tc]=out;
    }

    auto isSame=[&](const string& a, int idxA, const string& b, int idxB)->bool{
        return a[idxA]==b[idxB];
    };

    string Sf;
    for(int i=0;i<R;i++){
        if(i==0){
            Sf = finalStr[i];
        }else{
            int prevLen = (int)Sf.size();
            int curFirst = charToBit(S[i][0]);
            int prevLast = charToBit(Sf.back());
            bool prevLastSame = (prevLast==curFirst);
            bool prevLenEven = (prevLen%2==0);

            if(prevLenEven){
                Sf.push_back(prevLastSame? '%' : '$');
            }else{
                Sf.push_back(prevLastSame? '@' : '%');
            }
            Sf += finalStr[i];
        }
    }

    for(int i=0;i<R;i++){
        cout<<finalStr[i]<<"\n";
    }
    cout<<Sf;

    return 0;
}