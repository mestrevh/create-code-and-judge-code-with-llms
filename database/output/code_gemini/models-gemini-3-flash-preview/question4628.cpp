/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: UPA (Unicamp Portas Abertas)
 * Task: Calculate the minimum parking space length needed (20m per bus).
 * Strategy: Find the maximum number of overlapping bus intervals. 
 * Reusing space is allowed if Arrival >= Departure of another bus.
 * Complexity: O(N log N) for sorting events.
 */

int main() {
    // Optimize I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // Each bus creates two events: arrival and departure.
    // To handle the rule CB >= PA (reuse space if arrival equals departure),
    // we must process departures before arrivals at the same timestamp.
    // Using -1 for departure and 1 for arrival allows std::pair's default 
    // sorting to put (time, -1) before (time, 1).
    vector<pair<int, int>> events;
    events.reserve(2 * n);

    for (int i = 0; i < n; ++i) {
        int arrival, departure;
        cin >> arrival >> departure;
        events.push_back({arrival, 1});
        events.push_back({departure, -1});
    }

    // Sort events by time, then by type (-1 before 1)
    sort(events.begin(), events.end());

    int max_buses = 0;
    int current_buses = 0;

    for (const auto& ev : events) {
        current_buses += ev.second;
        if (current_buses > max_buses) {
            max_buses = current_buses;
        }
    }

    // Total space is max overlapping buses times 20 meters.
    cout << (long long)max_buses * 20 << "\n";

    return 0;
}