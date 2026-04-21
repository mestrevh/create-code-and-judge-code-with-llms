/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using i128 = __int128_t;

struct Mat {
    int n;
    vector<vector<unsigned long long>> a;
    Mat(int n_=0, bool ident=false): n(n_), a(n_, vector<unsigned long long>(n_,0)) {
        if(ident){
            for(int i=0;i<n;i++) a[i][i]=1;
        }
    }
};

static unsigned long long mulmodULL(unsigned long long x, unsigned long long y) {
    i128 r = (i128)x * (i128)y;
    return (unsigned long long)r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if(!(cin >> N)) return 0;

    Mat A(N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            unsigned long long v;
            cin >> v;
            A.a[i][j]=v;
        }
    }

    long long K;
    cin >> K;

    string P;
    cin >> P;

    auto multiply = [&](const Mat& X, const Mat& Y)->Mat{
        int n = X.n;
        Mat R(n);
        for(int i=0;i<n;i++){
            for(int k=0;k<n;k++){
                unsigned long long xik = X.a[i][k];
                if(xik==0) continue;
                for(int j=0;j<n;j++){
                    R.a[i][j] = (unsigned long long)((i128)R.a[i][j] + (i128)xik * (i128)Y.a[k][j]);
                }
            }
        }
        return R;
    };

    Mat result(N, true);
    Mat base = A;

    long long exp = K;
    while(exp > 0){
        if(exp & 1) result = multiply(result, base);
        exp >>= 1;
        if(exp) base = multiply(base, base);
    }

    unsigned long long S_mod_14 = 0;
    unsigned long long D_sum = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            unsigned long long v = result.a[i][j];
            S_mod_14 = (S_mod_14 + (unsigned long long)(v % 14ULL)) % 14ULL;
        }
        D_sum += result.a[i][i];
    }

    unsigned long long R = S_mod_14;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << result.a[i][j] << (j+1==N?'\n':' ');
        }
    }

    cout << "\n";

    if(D_sum % 2ULL == 1ULL) cout << "Ru" << R << "e30?" << " ";
    else cout << "Ru" << R << "?" << " ";

    string verdict;
    if(K>=0){
        if(R >= 12ULL) verdict = "Aff.. Nem vai dar tempo de cochilar antes da aula de " + P + ".";
        else if(R < 10ULL) verdict = "Eita, cedo demais..";
        else verdict = "Ainda bem, vai dar tempo de cochilar antes da aula de " + P + ".";
        cout << verdict;
    }

    return 0;
}