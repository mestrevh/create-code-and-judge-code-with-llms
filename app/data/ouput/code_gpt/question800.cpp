/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

struct Circle {
    int x, y, r;
};

int countZones(const std::vector<Circle>& circles) {
    int n = circles.size();
    std::set<int> zones;
    
    // Simular todas as combinações de círculos
    for (int i = 0; i < (1 << n); ++i) {
        int overlap = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                for (int k = j + 1; k < n; ++k) {
                    if (i & (1 << k)) {
                        int dx = circles[j].x - circles[k].x;
                        int dy = circles[j].y - circles[k].y;
                        int distance_squared = dx * dx + dy * dy;
                        int radii_sum = circles[j].r + circles[k].r;
                        if (distance_squared < radii_sum * radii_sum) {
                            overlap++;
                        }
                    }
                }
            }
        }
        zones.insert(overlap);
    }
    return zones.size();
}

int main() {
    while (true) {
        int W, H, n;
        std::cin >> W >> H >> n;
        if (W == 0 && H == 0 && n == 0) break;

        std::vector<Circle> circles(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> circles[i].x >> circles[i].y >> circles[i].r;
        }

        int zones = countZones(circles);
        std::cout << zones << std::endl;
    }
    return 0;
}
