/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Passenger {
    string name;
    int seat;
    int age;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<Passenger> passengers;
    int ticket;
    long long sum_ages = 0;

    while (cin >> ticket && ticket != -1) {
        string date, from, to, time;
        int seat, age;
        
        // Use cin >> ws to skip any leading whitespace/newlines before getline
        cin >> ws;
        if (!getline(cin, date)) break;
        
        cin >> ws;
        if (!getline(cin, from)) break;
        
        cin >> ws;
        if (!getline(cin, to)) break;
        
        cin >> ws;
        if (!getline(cin, time)) break;
        
        if (!(cin >> seat >> age)) break;
        
        cin >> ws;
        string name;
        if (!getline(cin, name)) break;

        passengers.push_back({name, seat, age});
        sum_ages += age;
    }

    if (!passengers.empty()) {
        double avg = (double)sum_ages / (double)passengers.size();
        for (const auto& p : passengers) {
            if ((double)p.age > avg && p.seat % 2 == 0) {
                cout << p.name << "\n";
            }
        }
    }

    return 0;
}