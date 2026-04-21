/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

std::vector<double> read_vector(int n) {
    std::vector<double> vec(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> vec[i];
    }
    return vec;
}

std::vector<double> convert_to_radians(const std::vector<double>& degrees) {
    const long double PI = std::acos(-1.0L);
    std::vector<double> radians;
    radians.reserve(degrees.size());
    for (double deg : degrees) {
        radians.push_back(static_cast<double>(deg * PI / 180.0L));
    }
    return radians;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (!(std::cin >> n)) return 0;

    std::vector<double> degrees = read_vector(n);
    std::vector<double> radians = convert_to_radians(degrees);

    std::cout << std::fixed << std::setprecision(5);
    for (size_t i = 0; i < radians.size(); ++i) {
        std::cout << radians[i] << (i == radians.size() - 1 ? "" : "\n");
    }
    std::cout << "\n";

    return 0;
}