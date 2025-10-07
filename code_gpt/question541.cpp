/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }
    
    std::sort(numbers.begin(), numbers.end());
    int menor = numbers[0];
    int meio = numbers[n / 2];
    int ultimo = numbers[n - 1];
    
    std::cout << menor << " " << meio << " " << ultimo << std::endl;
    return 0;
}
