/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int people;
    string city;
    int rooms;

    if (!(cin >> people >> city >> rooms)) return 0;

    for (auto &c : city) {
        c = tolower(c);
    }

    double house_cost = 0;
    double attraction_cost = 0;

    if (city == "pipa") {
        attraction_cost = 75.0 * people;
        if (rooms == 2) {
            house_cost = 600.0;
        } else if (rooms == 3) {
            house_cost = 900.0;
        }
    } else if (city == "fortaleza") {
        attraction_cost = 60.0 * people;
        if (rooms == 3) {
            house_cost = 950.0;
        } else if (rooms == 4) {
            house_cost = 1120.0;
        }
    }

    double total = house_cost + attraction_cost;
    double per_person = total / (double)people;

    cout << fixed << setprecision(2) << total << "\n";
    cout << fixed << setprecision(2) << per_person << "\n";

    return 0;
}