/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int k;
    std::cin >> k;

    for (int game = 0; game < k; ++game) {
        int n;
        std::cin >> n;
        std::string senha;
        std::cin >> senha;

        while (true) {
            std::string chute;
            std::cin >> chute;

            std::string zeros(n, '0');
            if (chute == zeros) {
                break;
            }

            int excelentes = 0;
            int bons = 0;

            std::vector<bool> senha_usada(n, false);
            std::vector<bool> chute_usado(n, false);

            for (int i = 0; i < n; ++i) {
                if (senha[i] == chute[i]) {
                    excelentes++;
                    senha_usada[i] = true;
                    chute_usado[i] = true;
                }
            }

            for (int i = 0; i < n; ++i) {
                if (chute_usado[i]) {
                    continue;
                }
                for (int j = 0; j < n; ++j) {
                    if (senha_usada[j]) {
                        continue;
                    }

                    if (chute[i] == senha[j]) {
                        bons++;
                        senha_usada[j] = true;
                        break;
                    }
                }
            }

            std::cout << "(" << excelentes << "," << bons << ")\n";

            if (excelentes == n) {
                break;
            }
        }
    }

    return 0;
}
