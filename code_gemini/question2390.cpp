/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

bool can_complete_trip(double initial_fuel, int n, int m, const std::vector<int>& a, const std::vector<int>& b) {
    double current_fuel = initial_fuel;
    double total_mass = static_cast<double>(m) + current_fuel;

    // Path sequence of planet indices: 1->2, 2->3, ..., (n-1)->n, n->1
    int path_from_indices[n];
    int path_to_indices[n];

    for (int i = 0; i < n - 1; ++i) {
        path_from_indices[i] = i;
        path_to_indices[i] = i + 1;
    }
    path_from_indices[n - 1] = n - 1;
    path_to_indices[n - 1] = 0;

    for (int i = 0; i < n; ++i) {
        // Takeoff
        double takeoff_coeff = a[path_from_indices[i]];
        if (takeoff_coeff <= 1.0) return false;
        double fuel_for_takeoff = total_mass / takeoff_coeff;
        if (fuel_for_takeoff > current_fuel) return false;
        current_fuel -= fuel_for_takeoff;
        total_mass -= fuel_for_takeoff;

        // Landing
        double land_coeff = b[path_to_indices[i]];
        if (land_coeff <= 1.0) return false;
        double fuel_for_land = total_mass / land_coeff;
        if (fuel_for_land > current_fuel) return false;
        current_fuel -= fuel_for_land;
        total_mass -= fuel_for_land;
    }

    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = 0; i < n; ++i) std::cin >> b[i];

    double low = 0.0;
    double high = 1e9 + 7.0; // A value larger than the max possible answer
    double ans = -1.0;

    for (int iter = 0; iter < 100; ++iter) {
        double mid = low + (high - low) / 2.0;
        if (can_complete_trip(mid, n, m, a, b)) {
            ans = mid;
            high = mid;
        } else {
            low = mid;
        }
    }

    if (ans < 0.0 || ans > 1e9 + 1) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(2) << ans << std::endl;
    }

    return 0;
}
