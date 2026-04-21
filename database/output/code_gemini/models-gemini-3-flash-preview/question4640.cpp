/*
Código criado pelo models/gemini-3-flash-preview
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Student> students(n);
    for (int i = 0; i < n; ++i) {
        cin >> students[i].name >> students[i].age >> students[i].grade;
    }

    // Processar Notas
    vector<Student> byGrade = students;
    sort(byGrade.begin(), byGrade.end(), [](const Student& a, const Student& b) {
        if (a.grade != b.grade) return a.grade < b.grade;
        return a.age < b.age;
    });

    cout << "---Notas---\n";
    double sumGrade = 0;
    for (int i = 0; i < n; ++i) {
        cout << byGrade[i].name << " " << fixed << setprecision(2) << byGrade[i].grade << "\n";
        sumGrade += byGrade[i].grade;
    }
    cout << "---------\n";
    cout << "Media Nota: " << fixed << setprecision(2) << sumGrade / (double)n << "\n";
    
    double medianGrade;
    if (n % 2 == 1) {
        medianGrade = byGrade[n / 2].grade;
    } else {
        medianGrade = (byGrade[n / 2 - 1].grade + byGrade[n / 2].grade) / 2.0;
    }
    cout << "Mediana Nota: " << fixed << setprecision(2) << medianGrade << "\n\n";

    // Processar Idade
    vector<Student> byAge = students;
    sort(byAge.begin(), byAge.end(), [](const Student& a, const Student& b) {
        if (a.age != b.age) return a.age < b.age;
        return a.grade < b.grade;
    });

    cout << "---Idade---\n";
    double sumAge = 0;
    for (int i = 0; i < n; ++i) {
        cout << byAge[i].name << " " << byAge[i].age << "\n";
        sumAge += (double)byAge[i].age;
    }
    cout << "---------\n";
    cout << "Media Idade: " << fixed << setprecision(2) << sumAge / (double)n << "\n";

    double medianAge;
    if (n % 2 == 1) {
        medianAge = (double)byAge[n / 2].age;
    } else {
        medianAge = (double)(byAge[n / 2 - 1].age + byAge[n / 2].age) / 2.0;
    }
    cout << "Mediana Idade: " << fixed << setprecision(2) << medianAge << "\n";

    return 0;
}