/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    const int VEC_SIZE = 10;
    
    std::vector<int> v1(VEC_SIZE);
    std::vector<int> v2(VEC_SIZE);
    std::vector<int> v3(VEC_SIZE);
    
    for (int i = 0; i < VEC_SIZE; ++i) {
        std::cin >> v1[i];
    }
    
    for (int i = 0; i < VEC_SIZE; ++i) {
        std::cin >> v2[i];
    }
    
    for (int i = 0; i < VEC_SIZE; ++i) {
        v3[i] = v1[i] + v2[i];
    }
    
    for (int i = 0; i < VEC_SIZE; ++i) {
        std::cout << v3[i] << (i == VEC_SIZE - 1 ? "" : " ");
    }
    std::cout << std::endl;
    
    return 0;
}
