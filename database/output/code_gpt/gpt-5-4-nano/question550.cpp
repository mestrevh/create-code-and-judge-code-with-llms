/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static long long mod_ll(long long a, long long m){
    if(m==0) return 0;
    long long r = a % m;
    if(r<0) r += m;
    return r;
}

static long long applyModulo(long long soma, long long A, long long B, long long C){
    long long div = A / B;
    long long m = div + C;
    return mod_ll(soma, m);
}

static tuple<long long,long long,long long> computeMax3(long long A,long long B,long long C,long long seedY,long long seedX,long long seedZ){
    array<long long,10> X{},Y{},Z{};
    Y[0]=seedY; X[0]=seedX; Z[0]=seedZ;
    for(int i=1;i<10;i++){
        Y[i]=(Y[i-1]*A + B)%C;
        X[i]=(X[i-1]*B + C)%A;
        Z[i]=(Z[i-1]*C + A)%B;
    }
    long long maxX=*max_element(X.begin(),X.end());
    long long maxY=*max_element(Y.begin(),Y.end());
    long long maxZ=*max_element(Z.begin(),Z.end());
    return {maxX,maxY,maxZ};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long A,B,C,seedX,seedY,seedZ;
    bool first=true;
    while ( (cin>>A>>B>>C>>seedX>>seedY>>seedZ) ){
        auto [maxX,maxY,maxZ]=computeMax3(A,B,C,seedY,seedX,seedZ);
        long long soma = maxX + maxY + maxZ;
        soma = applyModulo(soma,A,B,C);
        if(!first) cout << "\n";
        first=false;
        cout << soma;
    }
    return 0;
}