/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int passNumber;
    vector<int> ages;
    struct Passenger {
        int seat;
        int age;
        string name;
    };
    vector<Passenger> passengers;

    long long sumAges = 0;
    int count = 0;

    while (cin >> passNumber) {
        if (passNumber == -1) break;

        string date, from, to, time;
        int seat, age;
        string name;

        cin >> date >> from >> to >> time;
        cin >> seat >> age;

        int dummy;
        vector<string> parts;

        getline(cin, dummy ? *(new int(dummy)) : dummy);

        string line;
        if (!getline(cin, line)) break;
        while (line.size() == 0) {
            if (!getline(cin, line)) break;
        }

        if (line.find_first_not_of(" \t\r\n") == string::npos) break;

        name = line;
        while (!name.empty() && (name.back() == '\r' || name.back() == '\n')) name.pop_back();

        passengers.push_back({seat, age, name});
        sumAges += age;
        count++;
    }

    if (count == 0) return 0;
    double avg = (double)sumAges / (double)count;

    for (const auto& p : passengers) {
        if (p.age > avg && p.seat % 2 == 0) cout << p.name << "\n";
    }

    return 0;
}