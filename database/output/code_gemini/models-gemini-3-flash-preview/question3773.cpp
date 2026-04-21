/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

void swap_values(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}

struct Student {
    std::string name;
    int age;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    const int TOTAL_STUDENTS = 5;
    std::vector<Student> students(TOTAL_STUDENTS);
    std::vector<double> grades(TOTAL_STUDENTS);

    for (int i = 0; i < TOTAL_STUDENTS; ++i) {
        if (!(std::cin >> students[i].name)) break;
        std::cin >> grades[i] >> students[i].age;
    }

    for (int i = 0; i < TOTAL_STUDENTS - 1; ++i) {
        for (int j = 0; j < TOTAL_STUDENTS - i - 1; ++j) {
            if (grades[j] > grades[j + 1]) {
                swap_values(grades[j], grades[j + 1]);
            }
        }
    }

    std::cout << std::fixed << std::setprecision(2);
    for (int i = 0; i < TOTAL_STUDENTS; ++i) {
        std::cout << students[i].name << " " << grades[i] << " " << students[i].age << "\n";
    }

    return 0;
}