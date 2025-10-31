/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>

int main() {
    std::string line1, line2;
    std::getline(std::cin, line1);
    std::getline(std::cin, line2);
    
    std::istringstream ss1(line1), ss2(line2);
    std::set<int> set2;
    std::vector<int> vec1;
    int num;

    while (ss2 >> num) {
        set2.insert(num);
    }

    while (ss1 >> num) {
        if (set2.find(num) == set2.end()) {
            vec1.push_back(num);
        }
    }

    std::sort(vec1.rbegin(), vec1.rend());
    for (size_t i = 0; i < vec1.size(); ++i) {
        std::cout << vec1[i];
        if (i < vec1.size() - 1) std::cout << " ";
    }
    return 0;
}
