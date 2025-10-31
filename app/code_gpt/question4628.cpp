/*
Código criado pelo GPT 4o-mini
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

bool compare(Bus a, Bus b) {
    return a.arrival < b.arrival;
}

int main() {
    int N;
    cin >> N;
    vector<Bus> buses(N);
    
    for (int i = 0; i < N; i++) {
        cin >> buses[i].arrival >> buses[i].departure;
    }
    
    sort(buses.begin(), buses.end(), compare);
    
    vector<int> endTimes;
    
    for (const Bus& bus : buses) {
        bool parked = false;
        for (auto& endTime : endTimes) {
            if (bus.arrival >= endTime) {
                endTime = bus.departure;
                parked = true;
                break;
            }
        }
        if (!parked) {
            endTimes.push_back(bus.departure);
        }
    }
    
    int totalSpace = endTimes.size() * 20;
    cout << totalSpace << endl;
    
    return 0;
}
