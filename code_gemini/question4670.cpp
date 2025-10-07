/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Student {
    double avg;
    int periods;
    int index;

    bool operator<(const Student& other) const {
        if (abs(avg - other.avg) < 1e-9) {
            return periods > other.periods;
        }
        return avg > other.avg;
    }
};

int main() {
    int v, p, c;
    cin >> v >> p;

    vector<double> celo_grades(p);
    double celo_sum = 0;
    for (int i = 0; i < p; ++i) {
        cin >> celo_grades[i];
        celo_sum += celo_grades[i];
    }

    cin >> c;

    vector<Student> students(c + 1);
    students[0].avg = celo_sum / p;
    students[0].periods = p;
    students[0].index = 0;

    for (int i = 1; i <= c; ++i) {
        int cp;
        cin >> cp;
        double competitor_sum = 0;
        for (int j = 0; j < cp; ++j) {
            double grade;
            cin >> grade;
            competitor_sum += grade;
        }
        students[i].avg = competitor_sum / cp;
        students[i].periods = cp;
        students[i].index = i;
    }

    sort(students.begin(), students.end());

    int celo_rank = 0;
    for (int i = 0; i < students.size(); ++i) {
        if (students[i].index == 0) {
            celo_rank = i + 1;
            break;
        }
    }

    if (celo_rank <= v) {
        cout << "Matriculado, seu ranking é " << celo_rank << " dentre as " << v << " vagas" << endl;
    } else {
        cout << "Se não tivesse pago Dominó " << p << ", teria entrado..." << endl;
    }

    return 0;
}
