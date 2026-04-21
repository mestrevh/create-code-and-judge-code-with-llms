/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool isPrime(long long x){
    if(x < 2) return false;
    if(x % 2 == 0) return x == 2;
    for(long long d = 3; d*d <= x; d += 2){
        if(x % d == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if(!(cin >> N)) return 0;
    vector<vector<long long>> a(N, vector<long long>(N));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> a[i][j];

    for(int i = 0; i < N; i++){
        sort(a[i].begin(), a[i].end());
    }

    long long S = 0;
    for(int i = 0; i < N; i++) S += a[i][i];

    if(isPrime(S)){
        cout << "A soma resultou em um numero primo!\n";
    } else {
        cout << "A soma resultou em um numero nao primo!\n";
    }

    cout << S << "\n";

    vector<vector<long long>> b(N, vector<long long>(N, 0));

    if(isPrime(S)){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                long long val = a[j][i];
                if(val % 2 != 0) val *= 2;
                b[i][j] = val;
            }
        }
    } else {
        vector<long long> diag;
        diag.reserve(N);
        for(int i = 0; i < N; i++) diag.push_back(a[i][i]);
        sort(diag.begin(), diag.end());
        for(int i = 0; i < N; i++){
            long long val = diag[i];
            if(val % 2 != 0) val *= 2;
            b[i][i] = val;
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(i != j) b[i][j] = a[i][j];
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(j) cout << " ";
            cout << b[i][j];
        }
        cout << "\n";
    }

    return 0;
}