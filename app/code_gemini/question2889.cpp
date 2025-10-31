/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    const int N = 15;
    int codes[N];
    long long phones[N];

    for (int i = 0; i < N; ++i) {
        std::cin >> codes[i] >> phones[i];
    }

    int target_code;
    std::cin >> target_code;

    bool found = false;
    for (int i = 0; i < N; ++i) {
        if (codes[i] == target_code) {
            found = true;
            break;
        }
    }

    if (found) {
        std::cout << "Telefones com o codigo de area " << target_code << ":\n";
        for (int i = 0; i < N; ++i) {
            if (codes[i] == target_code) {
                std::cout << codes[i] << " " << phones[i] << "\n";
            }
        }
    } else {
        std::cout << "Nao ha nenhum telefone com o codigo " << target_code << "\n";
    }

    return 0;
}
