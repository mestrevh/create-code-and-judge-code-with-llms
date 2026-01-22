/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Box {
    int id;
    int x, y, z;
    double distance() const {
        return std::sqrt(x * x + y * y + z * z);
    }
};

bool compareBoxes(const Box& a, const Box& b) {
    if (a.distance() == b.distance()) return a.id < b.id;
    return a.distance() < b.distance();
}

int main() {
    while (true) {
        int N;
        std::cin >> N;
        if (N == 0) break;

        std::vector<Box> boxes(N);
        for (int i = 0; i < N; ++i) {
            boxes[i].id = i + 1;
            std::cin >> boxes[i].x >> boxes[i].y >> boxes[i].z;
        }

        std::vector<int> order;
        std::vector<bool> collected(N, false);
        int currentX = 0, currentY = 0, currentZ = 0;

        for (int count = 0; count < N; ++count) {
            std::vector<Box> candidates;
            for (int i = 0; i < N; ++i) {
                if (!collected[i]) {
                    candidates.push_back(boxes[i]);
                }
            }
            std::sort(candidates.begin(), candidates.end(), compareBoxes);
            collected[candidates[0].id - 1] = true;
            order.push_back(candidates[0].id);
            currentX = boxes[candidates[0].id - 1].x;
            currentY = boxes[candidates[0].id - 1].y;
            currentZ = boxes[candidates[0].id - 1].z;
        }
        
        for (size_t i = 0; i < order.size(); ++i) {
            std::cout << order[i] << (i + 1 < order.size() ? " " : "\n");
        }
    }
    return 0;
}
