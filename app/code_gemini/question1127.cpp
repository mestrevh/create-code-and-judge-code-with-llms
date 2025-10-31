/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Village {
    std::string name;
    long long x, y, z;
    int priority;
    long long dist_sq;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long px, py, pz;
    std::cin >> px >> py >> pz;

    std::vector<Village> villages = {
        {"Solitude", 140, 200, 456, 0, 0},
        {"Kakariko", 0, 64, 10, 1, 0},
        {"Hogsmeade", 34, 110, 220, 2, 0}
    };

    for (auto& v : villages) {
        long long dx = v.x - px;
        long long dy = v.y - py;
        long long dz = v.z - pz;
        v.dist_sq = dx * dx + dy * dy + dz * dz;
    }

    std::sort(villages.begin(), villages.end(), [](const Village& a, const Village& b) {
        if (a.dist_sq != b.dist_sq) {
            return a.dist_sq < b.dist_sq;
        }
        return a.priority < b.priority;
    });

    std::cout << villages[0].name << " " << villages[1].name << " " << villages[2].name << "\n";

    return 0;
}
