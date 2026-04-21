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

using namespace std;

struct Employee {
    string name;
    int age;
    double salary;
    int id;
};

bool compareAge(const Employee& a, const Employee& b) {
    if (a.age != b.age) return a.age < b.age;
    return a.id < b.id;
}

bool compareSalary(const Employee& a, const Employee& b) {
    if (a.salary != b.salary) return a.salary < b.salary;
    return a.id < b.id;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<Employee> employees;
    int op;
    while (cin >> op) {
        if (op == 1) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string name;
            if (!getline(cin, name)) break;
            int age;
            double salary;
            if (!(cin >> age >> salary)) break;
            employees.push_back({name, age, salary, (int)employees.size()});
        } else if (op == 2) {
            vector<Employee> sorted = employees;
            sort(sorted.begin(), sorted.end(), compareAge);
            cout << "Ordenado por idade:" << endl << endl;
            for (size_t i = 0; i < sorted.size(); ++i) {
                cout << " " << (i + 1) << " " << sorted[i].name << "\n";
                cout << "      " << sorted[i].age << "\n";
                cout << "      " << fixed << setprecision(2) << sorted[i].salary << "\n";
            }
        } else if (op == 3) {
            vector<Employee> sorted = employees;
            sort(sorted.begin(), sorted.end(), compareSalary);
            cout << "Ordenado por salario:" << endl << endl;
            for (size_t i = 0; i < sorted.size(); ++i) {
                cout << " " << (i + 1) << " " << sorted[i].name << "\n";
                cout << "      " << sorted[i].age << "\n";
                cout << "      " << fixed << setprecision(2) << sorted[i].salary << "\n";
            }
        } else if (op == 4) {
            cout << "Saindo..." << endl;
            break;
        }
    }

    return 0;
}