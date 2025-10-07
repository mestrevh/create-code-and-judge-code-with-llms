/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

long long solve(long long current_n, int current_t, int target_t) {
    if (current_t == target_t) {
        return current_n;
    }
    
    long long next_n;
    if ((current_t + 1) % 2 != 0) {
        next_n = current_n + 3;
    } else {
        next_n = current_n + (current_n % 5);
    }
    
    return solve(next_n, current_t + 1, target_t);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    long long n;
    int t;
    
    std::cin >> n >> t;
    
    std::cout << solve(n, 0, t) << std::endl;
    
    return 0;
}
