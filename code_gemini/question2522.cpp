/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iterator>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> a;
    int num;
    for (int i = 0; i < 5; ++i) {
        std::cin >> num;
        a.push_back(num);
    }

    std::unordered_set<int> b_set;
    for (int i = 0; i < 5; ++i) {
        std::cin >> num;
        b_set.insert(num);
    }

    std::vector<int> intersection;
    for (int val : a) {
        if (b_set.count(val)) {
            intersection.push_back(val);
        }
    }

    std::sort(intersection.begin(), intersection.end());

    for (size_t i = 0; i < intersection.size(); ++i) {
        std::cout << intersection[i] << (i == intersection.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;

    return 0;
}
