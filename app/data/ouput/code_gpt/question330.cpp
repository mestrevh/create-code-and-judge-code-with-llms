/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>
#include <algorithm>

struct Student {
    std::string code;
    std::string name;
    int age;
    int gender; // 0: female, 1: male
    double enemScore;
};

struct Discipline {
    std::string code;
    std::string name;
    std::vector<std::string> enrolledStudents;
};

int main() {
    int n, m, p;
    std::cin >> n;

    std::vector<Student> students(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> students[i].code;
        std::cin.ignore();
        std::getline(std::cin, students[i].name);
        std::cin >> students[i].age >> students[i].gender >> students[i].enemScore;
    }

    std::cin >> m;
    std::vector<Discipline> disciplines(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> disciplines[i].code;
        std::cin.ignore();
        std::getline(std::cin, disciplines[i].name);
    }

    std::cin >> p;
    std::map<std::string, std::vector<std::string>> enrollments;
    for (int i = 0; i < p; ++i) {
        std::string studentCode, disciplineCode;
        std::cin >> studentCode >> disciplineCode;
        enrollments[disciplineCode].push_back(studentCode);
    }

    int maleCount = 0, femaleCount = 0;
    double totalAge = 0.0, totalAgeAbove7_5 = 0.0;
    int countAbove7_5 = 0;

    for (const auto& student : students) {
        if (student.gender == 1) maleCount++;
        if (student.gender == 0) femaleCount++;
        totalAge += student.age;
        if (student.enemScore > 7.5) {
            totalAgeAbove7_5 += student.age;
            countAbove7_5++;
        }
    }

    std::cout << maleCount << "\n" << femaleCount << "\n";
    std::cout << std::fixed << std::setprecision(2) << totalAge / n << "\n";
    std::cout << std::fixed << std::setprecision(2) << (countAbove7_5 ? totalAgeAbove7_5 / countAbove7_5 : 0) << "\n";

    for (auto& discipline : disciplines) {
        std::string code = discipline.code;
        auto it = enrollments.find(code);
        if (it != enrollments.end()) {
            std::sort(it->second.begin(), it->second.end());
            std::cout << discipline.name << "\n" << it->second.size() << "\n";
            for (const auto& studentCode : it->second) {
                auto studentIt = std::find_if(students.begin(), students.end(), [&](const Student& s) {
                    return s.code == studentCode;
                });
                if (studentIt != students.end()) {
                    std::cout << studentIt->name << "\n";
                }
            }
        }
    }

    return 0;
}
