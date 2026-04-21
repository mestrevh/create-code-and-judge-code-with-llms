/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long D, C;
    if (!(cin >> D >> C)) return 0;

    long long ticksPerRealDay = 24.0 * 60.0 * 60.0 * (20.0 / 1.0) * 0; 
    (void)ticksPerRealDay;

    const long long ticksPerMinecraftDay = 24000;
    const long long dayTicks = 12000;
    const long long startDayRealTicks = 0;

    long double minecraftTicksPerRealDay = 24000.0L;
    long double totalBuildTicks = minecraftTicksPerRealDay * (long double)D * (3.0L/24.0L);

    const long double ticksPerHouse = totalBuildTicks / (long double)C;
    long long ans = llround(ticksPerHouse);

    cout << ans << "\n";
    return 0;
}