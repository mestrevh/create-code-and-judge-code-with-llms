/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct PilhaDupla {
    vector<long long> v;
    int topoE, topoD;

    PilhaDupla(int cap = 0) { init(cap); }

    void init(int cap) {
        v.assign(2 * cap + 5, 0);
        topoE = cap;      
        topoD = cap + 1;  
    }

    bool empilha(char lado, long long x) {
        if (lado == 'e') {
            if (topoE - 1 < 0) return false;
            v[--topoE] = x;
            return true;
        } else if (lado == 'd') {
            if (topoD + 1 >= (int)v.size()) return false;
            v[topoD++] = x;
            return true;
        }
        return false;
    }

    bool desempilha(char lado, long long &out) {
        if (lado == 'e') {
            if (topoE >= (int)v.size()) return false;
            if (topoE == (int)v.size()/2 && (topoE != (int)v.size()/2)) return false;
            if (topoE == (int)v.size()/2) return false;
            out = v[topoE++];
            return true;
        } else if (lado == 'd') {
            if (topoD == (int)v.size()/2 + 1) return false;
            out = v[--topoD];
            return true;
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    PilhaDupla pd(n + 5);

    for (int i = 0; i < n; i++) {
        char op;
        cin >> op;
        if (op == 'E') {
            char lado;
            long long x;
            cin >> lado >> x;
            pd.empilha(lado, x);
        } else if (op == 'D') {
            char lado;
            cin >> lado;
            long long out;
            pd.desempilha(lado, out);
            cout << out << "\n";
        }
    }
    return 0;
}