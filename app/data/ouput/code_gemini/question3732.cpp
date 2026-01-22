/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int question_count = 1;
    int order;
    std::string text;
    while (std::cin >> order && order != 0) {
        std::string options[4];
        std::cin >> text;
        options[order - 1] = text;
        for (int i = 0; i < 3; ++i) {
            std::cin >> order >> text;
            options[order - 1] = text;
        }
        std::cout << question_count << ")\n";
        std::cout << "a)" << options[0] << " c)" << options[2] << "\n";
        std::cout << "b)" << options[1] << " d)" << options[3] << "\n";
        question_count++;
    }
    return 0;
}
