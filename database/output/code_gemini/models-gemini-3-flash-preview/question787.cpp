/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

long long fastExp(long long a, int n) {
    if (n == 0) {
        return 1;
    }
    long long half = fastExp(a, n / 2);
    if (n % 2 == 0) {
        return half * half;
    } else {
        return a * half * half;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    long long a;
    int n;
    if (!(std::cin >> a >> n)) return 0;
    
    std::cout << fastExp(a, n) << std::endl;
    
    return 0;
}