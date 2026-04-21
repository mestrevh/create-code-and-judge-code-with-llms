/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> tipo = {0,1,2,3};

    auto getRate = [](int shake){
        if(shake==1) return 2.0;
        if(shake==2) return 3.0;
        return 4.0;
    };

    auto getDiscount = [](int shake, int mL){
        int base = mL % 100;
        int blocks = mL / 100;
        if(base) {
            int extra = 1;
            blocks += extra - 1;
        }
        bool above = mL > 500;
        int rate;
        if(shake==1) rate = above ? 10 : 5;
        else if(shake==2) rate = above ? 6 : 3;
        else rate = above ? 8 : 4;
        return rate;
    };

    auto priceShake = [&](int shake, int mL)->long long{
        int centsPer100;
        if(shake==1) centsPer100 = 20000;
        else if(shake==2) centsPer100 = 30000;
        else centsPer100 = 40000;

        int fullBlocks = mL / 100;
        int remainder = mL % 100;

        int discPct;
        if(shake==1) discPct = (mL > 500 ? 10 : 5);
        else if(shake==2) discPct = (mL > 500 ? 6 : 3);
        else discPct = (mL > 500 ? 8 : 4);

        auto cost100 = [&](int blockCount)->long long{
            long long cost = 1LL * centsPer100 * blockCount;
            long long discount = cost * discPct / 100;
            return cost - discount;
        };

        long long total = 0;
        total += cost100(fullBlocks);
        if(remainder > 0){
            long long base = 1LL * centsPer100 * remainder / 100;
            long long discount = base * discPct / 100;
            total += base - discount;
        }
        return total;
    };

    long long x1, x2;
    long long m1, m2;
    long long R;
    if(!(cin >> x1)) return 0;
    cin >> x2 >> m1 >> m2 >> R;

    long long centsR = R * 100;

    auto initialCost = [&]()->long long{
        return priceShake((int)x1, (int)m1) + priceShake((int)x2, (int)m2);
    };

    long long cost1 = initialCost();
    if(cost1 > centsR){
        cout << "Carambolas! O shake JA ERA.\n";
        return 0;
    }

    long long low = 1, high = 1;
    while(true){
        long long nm1 = m1 * high;
        long long nm2 = m2 * high;
        if(nm1 > (long long)1e9 || nm2 > (long long)1e9) break;

        long long c = priceShake((int)x1, (int)nm1) + priceShake((int)x2, (int)nm2);
        if(c <= centsR) high *= 2;
        else break;
    }

    long long ans = 1;
    while(low <= high){
        long long mid = low + (high - low)/2;
        long long nm1 = m1 * mid;
        long long nm2 = m2 * mid;
        long long c = priceShake((int)x1, (int)nm1) + priceShake((int)x2, (int)nm2);
        if(c <= centsR){
            ans = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    if(ans > 1){
        cout << "Yeah! Shake " << ans << " vezes mais.\n";
    }else{
        cout << "De qualquer forma matamos nossa sede de shake.\n";
    }
    return 0;
}