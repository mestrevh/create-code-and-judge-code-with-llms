/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<std::string> turma1;
    std::vector<std::string> turma2;
    std::vector<std::string> turma3;

    std::string name;
    int class_number;

    while (std::getline(std::cin, name)) {
        if (name.empty()) {
            continue;
        }

        std::cin >> class_number;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (class_number == 1) {
            turma1.push_back(name);
        } else if (class_number == 2) {
            turma2.push_back(name);
        } else if (class_number == 3) {
            turma3.push_back(name);
        }
    }

    std::cout << "Turma 1:" << std::endl;
    for (const std::string& student_name : turma1) {
        std::cout << student_name << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Turma 2:" << std::endl;
    for (const std::string& student_name : turma2) {
        std::cout << student_name << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Turma 3:" << std::endl;
    for (const std::string& student_name : turma3) {
        std::cout << student_name << std::endl;
    }

    return 0;
}
