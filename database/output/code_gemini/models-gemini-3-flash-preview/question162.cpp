/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<int> arrivals(N);
    vector<int> departures(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> arrivals[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> departures[i];
    }
    
    int timeline[1002];
    for (int i = 0; i < 1002; ++i) timeline[i] = 0;
    
    for (int i = 0; i < N; ++i) {
        int start = arrivals[i];
        int end = departures[i];
        // Guest is present in the interval [arrival, departure)
        // Since the times are small (up to 1000), we can increment each point
        for (int t = start; t < end; ++t) {
            timeline[t]++;
        }
    }
    
    int max_guests = 0;
    for (int i = 0; i < 1002; ++i) {
        if (timeline[i] > max_guests) {
            max_guests = timeline[i];
        }
    }
    
    cout << max_guests << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    
    return 0;
}