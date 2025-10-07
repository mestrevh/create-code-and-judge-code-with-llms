/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canCoverAllCities(const vector<int>& cities, const vector<int>& antennas, int r) {
    int j = 0, n = cities.size(), m = antennas.size();
    for (int i = 0; i < n; ++i) {
        while (j < m && antennas[j] < cities[i] - r) j++;
        if (j < m && antennas[j] <= cities[i] + r) continue;
        return false;
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> cities(n), antennas(m);
    for (int i = 0; i < n; ++i) cin >> cities[i];
    for (int i = 0; i < m; ++i) cin >> antennas[i];

    sort(cities.begin(), cities.end());
    sort(antennas.begin(), antennas.end());

    int low = 0, high = 1e9, answer = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canCoverAllCities(cities, antennas, mid)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << answer << endl;
    return 0;
}
