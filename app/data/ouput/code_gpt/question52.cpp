/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

bool isPerfect(int num) {
    int sum = 1;
    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum == num;
}

int main() {
    int n;
    std::cin >> n;
    
    for (int i = 2; i < n; ++i) {
        if (isPerfect(i)) {
            std::cout << i << std::endl;
        }
    }
    return 0;
}
