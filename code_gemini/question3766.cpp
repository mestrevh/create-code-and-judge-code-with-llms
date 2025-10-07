/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <limits>

struct Box {
    int id;
    long long x, y, z;
};

long long distSq(long long x1, long long y1, long long z1, long long x2, long long y2, long long z2) {
    long long dx = x1 - x2;
    long long dy = y1 - y2;
    long long dz = z1 - z2;
    return dx * dx + dy * dy + dz * dz;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    while (std::cin >> n && n != 0) {
        std::vector<Box> boxes(n);
        for (int i = 0; i < n; ++i) {
            boxes[i].id = i + 1;
            std::cin >> boxes[i].x >> boxes[i].y >> boxes[i].z;
        }

        std::vector<bool> collected(n, false);
        long long currentX = 0, currentY = 0, currentZ = 0;

        for (int i = 0; i < n; ++i) {
            long long min_dist_sq = -1;
            int best_box_idx = -1;

            for (int j = 0; j < n; ++j) {
                if (!collected[j]) {
                    long long d_sq = distSq(currentX, currentY, currentZ, boxes[j].x, boxes[j].y, boxes[j].z);

                    if (best_box_idx == -1 || d_sq < min_dist_sq) {
                        min_dist_sq = d_sq;
                        best_box_idx = j;
                    } else if (d_sq == min_dist_sq) {
                        if (boxes[j].id < boxes[best_box_idx].id) {
                            best_box_idx = j;
                        }
                    }
                }
            }

            std::cout << boxes[best_box_idx].id << (i == n - 1 ? "" : " ");

            collected[best_box_idx] = true;
            currentX = boxes[best_box_idx].x;
            currentY = boxes[best_box_idx].y;
            currentZ = boxes[best_box_idx].z;
        }
        std::cout << "\n";
    }

    return 0;
}
