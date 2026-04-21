/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef __int128_t int128;

struct Point {
    long long x, y;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<Point> p(N);
    for (int i = 0; i < N; ++i) {
        cin >> p[i].x >> p[i].y;
    }

    // Shoelace formula: 2 * Area = sum(x_i * y_{i+1} - x_{i+1} * y_i)
    // The problem states Volume = 2 * Area, so the Shoelace sum is the Volume.
    // Using __int128 for prefix sums as intermediate sums can exceed long long.
    vector<int128> s(2 * N + 1, 0);
    for (int i = 0; i < 2 * N; ++i) {
        int128 term = (int128)p[i % N].x * p[(i + 1) % N].y - (int128)p[(i + 1) % N].x * p[i % N].y;
        s[i + 1] = s[i] + term;
    }

    int128 total_v = s[N];

    // Function to calculate Volume of piece formed by vertices p[i...j]
    auto get_v1 = [&](int i, int j) -> int128 {
        int128 area2 = s[j] - s[i];
        area2 += (int128)p[j % N].x * p[i % N].y - (int128)p[i % N].x * p[j % N].y;
        return area2;
    };

    int128 min_max_carla = -1;
    int j = 2; // Initial far vertex for two-pointer

    // Carol chooses vertex i.
    for (int i = 0; i < N; ++i) {
        // Carla picks vertex j to maximize her volume: min(v1, total_v - v1).
        // This occurs when v1 is as close as possible to total_v / 2.
        // Vertex j must not be adjacent to i: j is in [i+2, i+N-2].
        if (j <= i + 1) j = i + 2;
        
        while (j + 1 <= i + N - 2) {
            int128 v1_curr = get_v1(i, j);
            int128 v1_next = get_v1(i, j + 1);
            
            // Compare which v1 is closer to total_v / 2 using |2*v1 - total_v|
            int128 diff_curr = (total_v > 2 * v1_curr) ? (total_v - 2 * v1_curr) : (2 * v1_curr - total_v);
            int128 diff_next = (total_v > 2 * v1_next) ? (total_v - 2 * v1_next) : (2 * v1_next - total_v);
            
            if (diff_next <= diff_curr) {
                j++;
            } else {
                break;
            }
        }
        
        int128 v1 = get_v1(i, j);
        int128 carla_v_for_i = (v1 < total_v - v1) ? v1 : (total_v - v1);
        
        // Carol wants to choose i such that Carla's maximum volume is minimized.
        if (min_max_carla == -1 || carla_v_for_i < min_max_carla) {
            min_max_carla = carla_v_for_i;
        }
    }

    // Final volumes fit in long long (max ~8e16 for given constraints)
    long long carol_final_volume = (long long)(total_v - min_max_carla);
    long long carla_final_volume = (long long)min_max_carla;

    cout << carol_final_volume << " " << carla_final_volume << endl;

    return 0;
}