/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> arr(n);
    for (int j = 0; j < n; ++j) {
        std::cin >> arr[j];
    }
    
    int i, x;
    std::cin >> i >> x;
    
    long long sum = 0;
    for (int j = 0; j < x; ++j) {
        sum += arr[(i + j) % n];
    }
    
    std::cout << sum << std::endl;
    return 0;
}
