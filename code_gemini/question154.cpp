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
    int C;
    std::cin >> C;
    std::string estrada;
    std::cin >> estrada;
    int total_paineis = 0;
    for (char trecho : estrada) {
        switch (trecho) {
            case 'P':
            case 'C':
                total_paineis += 2;
                break;
            case 'A':
                total_paineis += 1;
                break;
            case 'D':
                break;
        }
    }
    std::cout << total_paineis << std::endl;
    return 0;
}
