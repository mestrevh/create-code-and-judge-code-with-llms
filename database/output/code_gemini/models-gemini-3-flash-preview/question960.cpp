/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <cmath>

using namespace std;

struct Student {
    int matricula;
    string nome;
    double nota;
};

bool compareStudents(const Student& a, const Student& b) {
    if (abs(a.nota - b.nota) > 1e-9) {
        return a.nota < b.nota;
    }
    return a.matricula < b.matricula;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        vector<Student> students;
        double sum = 0.0;
        for (int i = 0; i < n; ++i) {
            string line;
            if (!getline(cin, line)) break;
            if (line.empty()) {
                i--;
                continue;
            }

            size_t firstHyphen = line.find('-');
            size_t lastHyphen = line.rfind('-');

            if (firstHyphen != string::npos && lastHyphen != string::npos && firstHyphen != lastHyphen) {
                Student s;
                try {
                    s.matricula = stoi(line.substr(0, firstHyphen));
                    s.nome = line.substr(firstHyphen + 1, lastHyphen - firstHyphen - 1);
                    s.nota = stod(line.substr(lastHyphen + 1));
                    sum += s.nota;
                    students.push_back(s);
                } catch (...) {
                    continue;
                }
            }
        }

        if (students.empty()) {
            if (n > 0) {
                cout << "Alunos abaixo da media:\n";
                cout << "Alunos iguais ou acima da media:\n";
                cout << "Media = 0.00" << endl;
            }
            continue;
        }

        double average = sum / (double)students.size();
        sort(students.begin(), students.end(), compareStudents);

        cout << "Alunos abaixo da media:\n";
        for (const auto& s : students) {
            if (s.nota < average - 1e-9) {
                cout << "Matricula: " << s.matricula << " Nome: " << s.nome << " Nota: " << fixed << setprecision(1) << s.nota << "\n";
            }
        }

        cout << "Alunos iguais ou acima da media:\n";
        for (const auto& s : students) {
            if (s.nota >= average - 1e-9) {
                cout << "Matricula: " << s.matricula << " Nome: " << s.nome << " Nota: " << fixed << setprecision(1) << s.nota << "\n";
            }
        }

        cout << "Media = " << fixed << setprecision(2) << average << endl;
    }

    return 0;
}