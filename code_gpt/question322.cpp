/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <limits>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> array(N);
    
    for (int i = 0; i < N; ++i) {
        std::cin >> array[i];
    }
    
    int min_value = std::numeric_limits<int>::max();
    int min_position = -1;
    
    for (int i = 0; i < N; ++i) {
        if (array[i] < min_value) {
            min_value = array[i];
            min_position = i;
        }
    }
    
    std::cout << "Menor valor: " << min_value << std::endl;
    std::cout << "Posicao: " << min_position << std::endl;
    
    return 0;
}
