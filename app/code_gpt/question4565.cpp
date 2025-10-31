/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int main() {
    int op, n, m;
    std::cin >> op >> n;
    
    std::set<int> p1, p2;
    for (int i = 0, num; i < n; ++i) {
        std::cin >> num;
        p1.insert(num);
    }
    
    std::cin >> m;
    for (int i = 0, num; i < m; ++i) {
        std::cin >> num;
        p2.insert(num);
    }
    
    std::vector<int> result;
    if (op == 1) {
        result.insert(result.end(), p1.begin(), p1.end());
        result.insert(result.end(), p2.begin(), p2.end());
    } else {
        for (const auto& num : p1) {
            if (p2.count(num)) {
                result.push_back(num);
            }
        }
    }
    
    std::sort(result.begin(), result.end());
    if (result.empty()) {
        std::cout << "empty" << std::endl;
    } else {
        for (size_t i = 0; i < result.size(); ++i) {
            if (i > 0) std::cout << " ";
            std::cout << result[i];
        }
        std::cout << std::endl;
    }
    
    return 0;
}
