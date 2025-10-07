/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Bus {
    int arrival;
    int departure;
};

bool compareBuses(const Bus& a, const Bus& b) {
    return a.arrival < b.arrival;
}

int main() {
    int n;
    cin >> n;

    vector<Bus> buses(n);
    for (int i = 0; i < n; ++i) {
        cin >> buses[i].arrival >> buses[i].departure;
    }

    sort(buses.begin(), buses.end(), compareBuses);

    int max_overlap = 0;
    for (int i = 0; i < n; ++i) {
        int current_overlap = 0;
        for (int j = 0; j < n; ++j) {
            if (buses[j].arrival < buses[i].departure && buses[j].departure > buses[i].arrival) {
                current_overlap++;
            }
        }
        max_overlap = max(max_overlap, current_overlap);
    }

    cout << max_overlap * 20 << endl;

    return 0;
}
