/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int M, A, B;
    if (std::cin >> M >> A >> B) {
        int C = M - (A + B);
        int oldest = A;
        if (B > oldest) oldest = B;
        if (C > oldest) oldest = C;
        std::cout << oldest << "\n";
    }

    return 0;
}