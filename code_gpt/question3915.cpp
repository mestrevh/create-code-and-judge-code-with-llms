/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    int A, B, C;
    std::cin >> A >> B >> C;
    std::vector<std::string> operations;

    if (A * A == C) operations.push_back("Quadrado");
    if (A % B == C) operations.push_back("Resto");
    if (A * B == C) operations.push_back("Multi");
    if (B != 0 && A / B == C) operations.push_back("Div");
    if (A + B == C) operations.push_back("Soma");
    if (A - B == C) operations.push_back("Sub");

    if (operations.empty()) {
        std::cout << "Impossivel vitores" << std::endl;
        return 0;
    }

    int start_index = 0;
    if (std::find(operations.begin(), operations.end(), "Div") != operations.end()) start_index = 3;
    else if (std::find(operations.begin(), operations.end(), "Multi") != operations.end()) start_index = 2;
    else if (std::find(operations.begin(), operations.end(), "Soma") != operations.end()) start_index = 4;
    else if (std::find(operations.begin(), operations.end(), "Sub") != operations.end()) start_index = 5;

    for (int i = start_index; i < operations.size(); i++) {
        std::cout << (i == 0 ? operations[i] : "tambem " + operations[i]) << " Vitoris" << std::endl;
    }
    return 0;
}
