/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<int, int> flights;
    for (int i = 0; i < 37; ++i) {
        int flight_id, seats;
        if (!(cin >> flight_id >> seats)) break;
        flights[flight_id] = seats;
    }

    int customer_id;
    while (cin >> customer_id && customer_id != 9999) {
        int desired_flight;
        if (!(cin >> desired_flight)) break;

        auto it = flights.find(desired_flight);
        if (it != flights.end() && it->second > 0) {
            cout << customer_id << "\n";
            it->second--;
        } else {
            cout << "INDISPONIVEL\n";
        }
    }

    return 0;
}

