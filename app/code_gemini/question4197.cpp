/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Student {
    std::string name;
    std::string cpf;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<Student> students(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> students[i].name >> students[i].cpf;
    }

    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.name < b.name;
    });

    for (const auto& student : students) {
        std::string password = "";
        
        for (size_t i = 0; i < student.name.length(); ++i) {
            int shift = student.cpf[i] - '0';
            char original_char = student.name[i];
            char new_char = ((original_char - 'a' + shift) % 26) + 'a';
            password += new_char;
        }

        password += student.cpf.substr(9, 2);

        std::cout << student.name << " " << password << "\n";
    }

    return 0;
}
