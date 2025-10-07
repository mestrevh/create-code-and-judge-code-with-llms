/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Event {
    double time;
    bool isStart;

    bool operator<(const Event& other) const {
        if (time != other.time) {
            return time < other.time;
        }
        return !isStart; 
    }
};

int main() {
    int n;
    cin >> n;

    vector<Event> events;
    for (int i = 0; i < n; ++i) {
        double a, b;
        cin >> a >> b;
        events.push_back({a, true});
        events.push_back({b, false});
    }

    sort(events.begin(), events.end());

    int maxOverlap = 0;
    int currentOverlap = 0;
    for (const auto& event : events) {
        if (event.isStart) {
            currentOverlap++;
            maxOverlap = max(maxOverlap, currentOverlap);
        } else {
            currentOverlap--;
        }
    }

    cout << maxOverlap << endl;

    return 0;
}
