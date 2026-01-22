/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, X;
    std::cin >> N >> X;

    std::vector<int> password(N);
    password[0] = X;
    
    int numOnes = N - 2; // Reserve 1 for zero, at least one 1 is mandatory.
    password[1] = 0; // First remaining must be 0
    if (numOnes > 0) {
        for (int i = 2; i < numOnes + 2; ++i) {
            password[i] = 1;
        }
    }

    // Sort to keep zeros on the left
    std::sort(password.begin() + 1, password.end());

    for (int i = 0; i < N; ++i) {
        std::cout << password[i] << (i == N - 1 ? "" : " ");
    }
    return 0;
}
