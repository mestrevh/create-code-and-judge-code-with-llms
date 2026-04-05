/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

void amadoProfessor(int n) {
    for (int i = 1; i <= 10; ++i) {
        std::cout << n << " x " << i << " =  " << (n * i) << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (std::cin >> n) {
        amadoProfessor(n);
    }

    return 0;
}