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

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::string instr, op1, op2;
        std::cin >> instr >> op1 >> op2;

        op1.pop_back();

        if (instr == "mov") {
            std::cout << op1 << " = " << op2 << "\n";
        } else if (instr == "add") {
            std::cout << op1 << " += " << op2 << "\n";
        } else if (instr == "sub") {
            std::cout << op1 << " -= " << op2 << "\n";
        } else if (instr == "and") {
            std::cout << op1 << " = " << op1 << " & " << op2 << "\n";
        }
    }

    return 0;
}
