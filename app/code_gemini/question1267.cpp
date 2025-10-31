/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<std::string> grifinoria;
    std::vector<std::string> sonserina;
    std::vector<std::string> corvinal;
    std::vector<std::string> lufa_lufa;
    for (int i = 0; i < n; ++i) {
        std::string nome, caracteristica;
        std::cin >> nome >> caracteristica;
        if (caracteristica == "coragem" || caracteristica == "determinacao") {
            grifinoria.push_back(nome);
        } else if (caracteristica == "astucia" || caracteristica == "ambicao") {
            sonserina.push_back(nome);
        } else if (caracteristica == "inteligencia" || caracteristica == "forca de vontade") {
            corvinal.push_back(nome);
        } else if (caracteristica == "lealdade" || caracteristica == "companheirismo") {
            lufa_lufa.push_back(nome);
        }
    }
    std::cout << "Grifinoria:" << '\n';
    for (const auto& nome : grifinoria) {
        std::cout << nome << '\n';
    }
    std::cout << "Sonserina:" << '\n';
    for (const auto& nome : sonserina) {
        std::cout << nome << '\n';
    }
    std::cout << "Corvinal:" << '\n';
    for (const auto& nome : corvinal) {
        std::cout << nome << '\n';
    }
    std::cout << "Lufa-lufa:" << '\n';
    for (const auto& nome : lufa_lufa) {
        std::cout << nome << '\n';
    }
    return 0;
}
