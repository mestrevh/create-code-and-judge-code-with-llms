/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n1, n2;
    std::cin >> n1 >> n2;
    std::vector<int> L1(n1), L2(n2), L(n1 + n2);
    
    for (int i = 0; i < n1; ++i) std::cin >> L1[i];
    for (int i = 0; i < n2; ++i) std::cin >> L2[i];
    
    std::merge(L1.begin(), L1.end(), L2.begin(), L2.end(), L.begin());
    
    for (const auto& elem : L) std::cout << elem << '\n';
    
    return 0;
}
