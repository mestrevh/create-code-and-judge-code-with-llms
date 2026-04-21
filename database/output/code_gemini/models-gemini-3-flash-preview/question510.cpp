/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int is_student, is_elderly;
    if (std::cin >> is_student >> is_elderly) {
        std::cout << ((is_student || is_elderly) ? 1 : 0) << std::endl;
    }
    return 0;
}