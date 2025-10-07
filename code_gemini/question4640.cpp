/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Student {
    string name;
    int age;
    double grade;
};

bool compareByGrade(const Student& a, const Student& b) {
    if (a.grade != b.grade) {
        return a.grade < b.grade;
    }
    return a.age < b.age;
}

bool compareByAge(const Student& a, const Student& b) {
    if (a.age != b.age) {
        return a.age < b.age;
    }
    return a.grade < b.grade;
}

int main() {
    int n;
    cin >> n;

    vector<Student> students(n);
    for (int i = 0; i < n; ++i) {
        cin >> students[i].name >> students[i].age >> students[i].grade;
    }

    sort(students.begin(), students.end(), compareByGrade);

    cout << "---Notas---" << endl;
    double sum_grades = 0;
    for (const auto& student : students) {
        cout << student.name << " " << fixed << setprecision(2) << student.grade << endl;
        sum_grades += student.grade;
    }
    cout << "---------" << endl;
    cout << "Media Nota: " << fixed << setprecision(2) << sum_grades / n << endl;
    cout << "Mediana Nota: " << fixed << setprecision(2) << (n % 2 == 0 ? (students[n / 2 - 1].grade + students[n / 2].grade) / 2 : students[n / 2].grade) << endl << endl;

    sort(students.begin(), students.end(), compareByAge);

    cout << "---Idade---" << endl;
    double sum_ages = 0;
    for (const auto& student : students) {
        cout << student.name << " " << student.age << endl;
        sum_ages += student.age;
    }
    cout << "---------" << endl;
    cout << "Media Idade: " << fixed << setprecision(2) << sum_ages / n << endl;
    cout << "Mediana Idade: " << fixed << setprecision(2) << (n % 2 == 0 ? (double)(students[n / 2 - 1].age + students[n / 2].age) / 2 : (double)students[n / 2].age) << endl;

    return 0;
}
