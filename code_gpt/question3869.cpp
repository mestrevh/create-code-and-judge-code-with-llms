/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

std::string translateInstruction(const std::string &instruction) {
    if (instruction.substr(0, 3) == "mov") {
        return instruction.substr(4) + " = " + instruction.substr(instruction.find(",") + 2);
    } else if (instruction.substr(0, 3) == "add") {
        return instruction.substr(4) + " += " + instruction.substr(instruction.find(",") + 2);
    } else if (instruction.substr(0, 3) == "sub") {
        return instruction.substr(4) + " -= " + instruction.substr(instruction.find(",") + 2);
    } else if (instruction.substr(0, 3) == "and") {
        return instruction.substr(4) + " = " + instruction.substr(4) + " & " + instruction.substr(instruction.find(",") + 2);
    }
    return "";
}

int main() {
    int N;
    std::cin >> N;
    std::cin.ignore();
    
    for (int i = 0; i < N; ++i) {
        std::string instruction;
        std::getline(std::cin, instruction);
        std::cout << translateInstruction(instruction) << std::endl;
    }
    return 0;
}
