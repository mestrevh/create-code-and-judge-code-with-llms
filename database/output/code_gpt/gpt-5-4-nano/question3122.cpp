/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long D;
    int C;
    if (!(cin >> D)) return 0;
    cin >> C;
    
    long long ticksPerRealDay = 3LL * 60LL * 60LL * 20LL;
    long long totalTicksAvailable = D * ticksPerRealDay;
    long long dayTicks = 12000;
    
    long long usableTicks = D * dayTicks;
    long long constructionTicks = (usableTicks / totalTicksAvailable) ? (totalTicksAvailable) : totalTicksAvailable;
    long long perHouse = totalTicksAvailable / C;
    
    cout << perHouse << "\n";
    return 0;
}