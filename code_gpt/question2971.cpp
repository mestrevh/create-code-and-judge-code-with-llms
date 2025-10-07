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
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }
    std::sort(A.begin(), A.end());
    for (int i = 0; i < N; ++i) {
        std::cout << A[i];
        if (i < N - 1) std::cout << " ";
    }
    std::cout << std::endl;
    return 0;
}
