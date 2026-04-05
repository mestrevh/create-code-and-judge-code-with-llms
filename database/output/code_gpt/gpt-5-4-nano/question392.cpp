/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double totalMinutes = 0.0;
    long long count = 0;
    long long minuteLimit = 40;
    long long freeCalls = 10;
    double packetCost = 10.0;
    double overCostPerMinute = 0.20;

    long long x;
    while (cin >> x) {
        if (x == 0) break;
        totalMinutes += x;
        count++;
    }

    double total = packetCost;
    if (count == 0) {
        total = packetCost;
    } else {
        if (count > freeCalls) {
            total += (count - freeCalls) * minuteLimit * overCostPerMinute;
        } else {
            total += max(0.0, totalMinutes - (double)minuteLimit) * overCostPerMinute;
        }
    }

    cout << fixed << setprecision(2) << total;
    return 0;
}