/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool isPrime(int x){
    if(x < 2) return false;
    if(x % 2 == 0) return x == 2;
    for(int d = 3; 1LL*d*d <= x; d += 2)
        if(x % d == 0) return false;
    return true;
}

static int nextPrime(int x){
    int y = x + 1;
    while(!isPrime(y)) y++;
    return y;
}

static int sumDigits(int x){
    x = abs(x);
    int s = 0;
    while(x > 0){
        s += x % 10;
        x /= 10;
    }
    return s;
}

static int transformPos(int code, int pos){
    long long total = 0;
    for(long long k = 6; k < code; k += 6) total += k;
    long long res = total - pos;
    long long mod = code == 0 ? 0 : ( (res % code) + code ) % code;
    return (int)mod;
}

void MudancaDeLivros(int *codigo, int *posicao){
    int m = *codigo;
    int n = *posicao;

    int dp = nextPrime(m);
    int sd = sumDigits(m);
    long long newCode = ( (long long)m + dp ) / sd;
    long long newPos = transformPos(m, n);

    *codigo = (int)newCode;
    *posicao = (int)newPos;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> cod, pos;
    int m, n;
    while(cin >> m >> n){
        if(m == 0) break;
        cod.push_back(m);
        pos.push_back(n);
    }

    vector<int> newCod(cod.size()), newPos(cod.size());
    unordered_set<int> usedCode, usedPos;
    vector<int> order;
    order.reserve(cod.size());

    for(size_t i = 0; i < cod.size(); i++){
        int c = cod[i], p = pos[i];
        MudancaDeLivros(&c, &p);

        while(usedCode.count(c)) c += 1;
        while(usedPos.count(p)) p += 1;

        newCod[i] = c;
        newPos[i] = p;

        usedCode.insert(c);
        usedPos.insert(p);
        order.push_back((int)i);
    }

    for(int idx = (int)order.size() - 1; idx >= 0; idx--){
        int i = order[idx];
        cout << newCod[i] << " - " << newPos[i] << "\n";
    }
    return 0;
}