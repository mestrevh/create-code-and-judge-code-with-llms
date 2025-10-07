/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> arrivals(n);
    std::vector<int> departures(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> arrivals[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> departures[i];
    }

    std::vector<int> timeline(1002, 0);

    for (int i = 0; i < n; ++i) {
        timeline[arrivals[i]]++;
        timeline[departures[i]]--;
    }

    int max_guests = 0;
    int current_guests = 0;
    for (int i = 1; i < 1002; ++i) {
        current_guests += timeline[i];
        if (current_guests > max_guests) {
            max_guests = current_guests;
        }
    }

    std::cout << max_guests << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
