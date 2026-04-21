/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: Rede Celular (Cellular Network)
 * Approach: For each city, find the nearest antenna using binary search (std::lower_bound).
 * The minimum radius r needed for a specific city is the distance to its nearest antenna.
 * The answer for the whole problem is the maximum of these minimum distances.
 * Complexity: O(N log M) time and O(N + M) space.
 */

int main() {
    // Standard competitive programming I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<long long> cities(n);
    for (int i = 0; i < n; ++i) {
        cin >> cities[i];
    }

    vector<long long> antennas(m);
    for (int i = 0; i < m; ++i) {
        cin >> antennas[i];
    }

    long long min_r_global = 0;

    for (int i = 0; i < n; ++i) {
        long long city_pos = cities[i];
        
        // Find the first antenna with position >= city_pos
        auto it = lower_bound(antennas.begin(), antennas.end(), city_pos);
        
        long long closest_antenna_dist = 4e18; // Initialize with a very large value

        // Check the antenna at or to the right of the city
        if (it != antennas.end()) {
            closest_antenna_dist = min(closest_antenna_dist, *it - city_pos);
        }
        
        // Check the antenna to the left of the city
        if (it != antennas.begin()) {
            closest_antenna_dist = min(closest_antenna_dist, city_pos - *prev(it));
        }

        // The global radius r must be at least the distance to the nearest antenna for this city
        if (closest_antenna_dist > min_r_global) {
            min_r_global = closest_antenna_dist;
        }
    }

    cout << min_r_global << endl;

    return 0;
}