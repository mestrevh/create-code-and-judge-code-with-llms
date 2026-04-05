/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using i128 = __int128_t;

static i128 gcd_i128(i128 a, i128 b){
    if(a<0) a=-a;
    if(b<0) b=-b;
    while(b!=0){
        i128 r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long Mll, Nll;
    if(!(cin >> Mll >> Nll)) return 0;

    i128 M = Mll, N = Nll;
    i128 g = gcd_i128(M, N);

    i128 ans = (M + N) / g - 2;
    if(ans < 0) ans = 0;

    string out;
    if(ans == 0) out = "0";
    else{
        i128 x = ans;
        bool neg = false;
        if(x < 0){ neg = true; x = -x; }
        string s;
        while(x > 0){
            int digit = (int)(x % 10);
            s.push_back('0' + digit);
            x /= 10;
        }
        if(neg) s.push_back('-');
        reverse(s.begin(), s.end());
        out = s;
    }
    cout << out;
    return 0;
}