/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string neighborhood;
    if (!(cin >> neighborhood)) return 0;
    string day;
    if (!(cin >> day)) return 0;

    int hour = -1;
    if (!(cin >> hour)) hour = -1;

    set<string> area1 = {"Moon Knight", "Daredevil", "Jessica Jones"};
    set<string> area2 = {"WandaVision", "Loki", "Hawkeye"};

    bool in1 = area1.count(neighborhood);
    bool in2 = area2.count(neighborhood);

    if (!in1 && !in2) {
        cout << "Invalid Neighborhood";
        return 0;
    }

    bool available = false;
    if (in1) {
        if (day == "Tuesday" && hour >= 8 && hour <= 20) available = true;
    } else {
        if (day == "Wednesday" && hour >= 2 && hour <= 23) available = true;
    }

    cout << (available ? "Water Available" : "Water not Available");
    return 0;
}