/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long x, y;
    while (std::cin >> x >> y) {
        std::vector<long long> distances;
        long long d;
        while (std::cin >> d && d != 0) {
            distances.push_back(d);
        }

        auto it_start = std::lower_bound(distances.begin(), distances.end(), y);
        auto it_end = std::upper_bound(distances.begin(), distances.end(), x);

        long long start_pos = std::distance(distances.begin(), it_start) + 1;
        long long end_pos = std::distance(distances.begin(), it_end - 1) + 1;

        std::cout << start_pos << " " << end_pos << "\n";
    }

    return 0;
}
