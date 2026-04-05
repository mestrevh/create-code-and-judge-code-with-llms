/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using i128 = __int128_t;

static inline i128 ceil_div(i128 a, i128 b){
    if(b < 0){ a = -a; b = -b; }
    if(a >= 0) return (a + b - 1) / b;
    return a / b; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if(!(cin >> n)) return 0;

    while(n--){
        long long V1_ll, V2_ll, D1_ll, D2_ll;
        cin >> V1_ll >> V2_ll >> D1_ll >> D2_ll;

        i128 V1 = (i128)V1_ll;
        i128 V2 = (i128)V2_ll;
        i128 D1 = (i128)D1_ll;
        i128 D2 = (i128)D2_ll;

        auto canClodesWin = [&](i128 k)->bool{
            i128 dmg2 = D2 + 50*k;
            if(dmg2 <= 0) dmg2 = 1;

            i128 turnsClodes = ceil_div(V2, dmg2);
            i128 turnsBezaliel = ceil_div(V1, D1);

            return turnsBezaliel > turnsClodes;
        };

        i128 low = 0, high = 1;
        while(!canClodesWin(high)){
            high *= 2;
            if(high > (i128)4e18) break;
        }

        i128 best = -1;
        i128 l = low, r = high;
        while(l <= r){
            i128 m = (l + r) / 2;
            if(canClodesWin(m)){
                best = m;
                r = m - 1;
            }else{
                l = m + 1;
            }
        }

        if(best != -1) cout << "Clodes\n";
        else cout << "Bezaliel\n";
    }

    return 0;
}