/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int city = 1;
    bool firstOutput = true;

    while (cin >> N) {
        if (N == 0) break;

        long long totalPeople = 0;
        long long totalConsumption = 0;

        map<int, long long> cntPeopleByAvgFloor;

        for (int i = 0; i < N; i++) {
            int X;
            int Y;
            cin >> X >> Y;
            totalPeople += X;
            totalConsumption += Y;
            int avgFloor = Y / X;
            cntPeopleByAvgFloor[avgFloor] += X;
        }

        if (!firstOutput) cout << "\n";
        firstOutput = false;

        cout << "Cidade# " << city++ << ":\n";
        bool firstPair = true;
        for (auto &p : cntPeopleByAvgFloor) {
            if (!firstPair) cout << ' ';
            firstPair = false;
            cout << p.second << '-' << p.first;
        }
        cout << "\n";
        double avg = (totalPeople == 0) ? 0.0 : (double)totalConsumption / (double)totalPeople;
        cout.setf(std::ios::fixed); 
        cout << "Consumo medio: " << setprecision(2) << avg << " m3.\n";
    }

    return 0;
}