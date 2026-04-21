/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Student {
    string name;
    double grade;
};

struct ClassRecord {
    vector<Student> students;
    double average;
};

ClassRecord read_class_data() {
    ClassRecord record;
    string token;
    double sum = 0;
    while (cin >> token && token != "*") {
        double grade;
        if (cin >> grade) {
            record.students.push_back({token, grade});
            sum += grade;
        }
    }
    if (record.students.empty()) {
        record.average = 0.0;
    } else {
        record.average = sum / (double)record.students.size();
    }
    return record;
}

Student determine_best_student(const ClassRecord& record) {
    Student best = {"", -1.0};
    for (const auto& s : record.students) {
        if (s.grade > best.grade) {
            best = s;
        }
    }
    return best;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> ws && cin.peek() != EOF) {
        ClassRecord classA = read_class_data();
        ClassRecord classB = read_class_data();

        if (classA.students.empty() && classB.students.empty()) {
            if (cin.eof()) break;
        }

        bool aWins = classA.average > 8.0;
        bool bWins = classB.average > 8.0;

        if (aWins && bWins) {
            cout << "Viagem para todos!" << endl;
        } else if (aWins) {
            cout << "Viagem para turma A" << endl;
        } else if (bWins) {
            cout << "Viagem para turma B" << endl;
        } else {
            cout << "Nenhuma das turmas viaja..." << endl;
        }

        Student bestA = determine_best_student(classA);
        Student bestB = determine_best_student(classB);
        
        Student bestOverall;
        if (bestA.grade > bestB.grade) {
            bestOverall = bestA;
        } else {
            bestOverall = bestB;
        }

        if (bestOverall.grade > 8.0) {
            cout << bestOverall.name << " ganhou viagem e ingresso no parque!" << endl;
            cout << "Nota: " << fixed << setprecision(2) << bestOverall.grade << endl;
        } else {
            cout << "Ninguem ganhou viagem e ingresso no parque..." << endl;
        }
    }

    return 0;
}