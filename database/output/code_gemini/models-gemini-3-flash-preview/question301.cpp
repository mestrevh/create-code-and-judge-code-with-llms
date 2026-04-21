/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        long long total_trucks = 0;
        long long total_price = 0;
        int max_days = 0;

        for (int i = 0; i < n; i++) {
            double weight, dist;
            int type;
            if (!(cin >> weight >> type >> dist)) break;

            int capacity, speed, cost_per_truck;
            if (type == 0) { // Normal delivery
                capacity = 10;
                speed = 100;
                cost_per_truck = 500;
            } else { // Express delivery
                capacity = 5;
                speed = 250;
                cost_per_truck = 1200;
            }

            int trucks_for_dest = (int)ceil(weight / (double)capacity);
            int days_for_dest = (int)ceil(dist / (double)speed);

            total_trucks += trucks_for_dest;
            total_price += (long long)trucks_for_dest * cost_per_truck;
            if (days_for_dest > max_days) {
                max_days = days_for_dest;
            }
        }

        cout << total_trucks << " " << total_price << " " << max_days << endl;
    }

    return 0;
}