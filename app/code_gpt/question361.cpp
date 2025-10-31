/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> rótulos(N);
    
    for (int i = 0; i < N; ++i) {
        std::cin >> rótulos[i];
    }
    
    int envelopes = *std::min_element(rótulos.begin(), rótulos.end());
    
    std::cout << envelopes << std::endl;
    
    return 0;
}
