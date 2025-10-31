/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

long long calculate_S(int n) {
    long long sum = 0;
    
    if (n % 2 == 0) {
        int count = 0;
        while (n % 2 == 0) {
            count++;
            n /= 2;
        }
        sum += (long long)count * 2;
    }
    
    for (int i = 3; (long long)i * i <= n; i += 2) {
        if (n % i == 0) {
            int count = 0;
            while (n % i == 0) {
                count++;
                n /= i;
            }
            sum += (long long)count * i;
        }
    }
    
    if (n > 1) {
        sum += n;
    }
    
    return sum;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int x;
    while (std::cin >> x && x != 0) {
        std::cout << calculate_S(x) << "\n";
    }
    
    return 0;
}
