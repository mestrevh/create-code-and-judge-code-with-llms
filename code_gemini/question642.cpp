/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <utility>

struct Point {
    long long x, y;
};

bool is_on_line(long long x, long long y, int a, int b) {
    return y == (long long)a * x + b;
}

long long get_side(long long x, long long y, int a, int b) {
    return (long long)a * x - y + b;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int num_test_cases;
    std::cin >> num_test_cases;

    for (int case_idx = 1; case_idx <= num_test_cases; ++case_idx) {
        int a, b;
        std::cin >> a >> b;

        std::vector<Point> coords_map;
        coords_map.reserve(65537);

        long long x = 0, y = 0;
        long long dx = 1, dy = 0;
        long long segment_length = 1;
        long long segment_passed = 0;
        int turn_count = 0;

        while (coords_map.size() <= 65535) {
            if (!is_on_line(x, y, a, b)) {
                coords_map.push_back({x, y});
            }

            x += dx;
            y += dy;
            segment_passed++;

            if (segment_passed == segment_length) {
                segment_passed = 0;
                
                long long temp_dx = dx;
                dx = dy;
                dy = -temp_dx;
                
                turn_count++;
                if (turn_count == 2) {
                    turn_count = 0;
                    segment_length++;
                }
            }
        }

        int K;
        std::cin >> K;
        std::cout << "Caso " << case_idx << "\n";

        for (int i = 0; i < K; ++i) {
            int m_idx, n_idx;
            std::cin >> m_idx >> n_idx;

            Point p1 = coords_map[m_idx];
            Point p2 = coords_map[n_idx];

            long long side1 = get_side(p1.x, p1.y, a, b);
            long long side2 = get_side(p2.x, p2.y, a, b);

            if (side1 * side2 > 0) {
                std::cout << "Mesmo lado da fronteira\n";
            } else {
                std::cout << "Lados opostos da fronteira\n";
            }
        }
    }

    return 0;
}
