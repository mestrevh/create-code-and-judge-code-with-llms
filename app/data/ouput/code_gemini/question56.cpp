/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <unordered_set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    const int P2_COUNT = 45;
    const int P3_COUNT = 30;

    std::vector<int> p2_enrollments(P2_COUNT);
    for (int i = 0; i < P2_COUNT; ++i) {
        std::cin >> p2_enrollments[i];
    }

    std::unordered_set<int> p3_set;
    for (int i = 0; i < P3_COUNT; ++i) {
        int enrollment;
        std::cin >> enrollment;
        p3_set.insert(enrollment);
    }

    for (int enrollment : p2_enrollments) {
        if (p3_set.count(enrollment)) {
            std::cout << enrollment << " ";
        }
    }

    std::cout << "\n";

    return 0;
}
