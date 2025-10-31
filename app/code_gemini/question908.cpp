/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::vector<int> arr(20);
    
    for (int i = 0; i < 20; ++i) {
        arr[i] = i * i;
    }
    
    for (int i = 0; i < 20; ++i) {
        std::cout << arr[i] << '\n';
    }
    
    return 0;
}
