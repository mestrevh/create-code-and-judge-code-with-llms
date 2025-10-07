/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <map>
#include <utility>

void solve() {
    std::map<std::pair<long long, long long>, int> endpoint_counts;
    for (int i = 0; i < 3; ++i) {
        long long x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        endpoint_counts[{x1, y1}]++;
        endpoint_counts[{x2, y2}]++;
    }

    if (endpoint_counts.size() != 3) {
        std::cout << "NAO\n";
        return;
    }

    std::vector<std::pair<long long, long long>> vertices;
    bool valid_counts = true;
    for (auto const& [point, count] : endpoint_counts) {
        if (count != 2) {
            valid_counts = false;
            break;
        }
        vertices.push_back(point);
    }

    if (!valid_counts) {
        std::cout << "NAO\n";
        return;
    }

    long long x1 = vertices[0].first;
    long long y1 = vertices[0].second;
    long long x2 = vertices[1].first;
    long long y2 = vertices[1].second;
    long long x3 = vertices[2].first;
    long long y3 = vertices[2].second;

    long long area_doubled = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);

    if (area_doubled == 0) {
        std::cout << "NAO\n";
    } else {
        std::cout << "SIM\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;
    while (N--) {
        solve();
    }

    return 0;
}
