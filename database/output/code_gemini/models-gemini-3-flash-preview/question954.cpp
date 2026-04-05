/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

struct Student {
    int id;
    string name;
    double grade;
};

bool compareStudents(const Student& a, const Student& b) {
    if (abs(a.grade - b.grade) > 1e-9) {
        return a.grade < b.grade;
    }
    return a.id < b.id;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    if (n <= 0) {
        cout << "Media = 0.00" << endl;
        return 0;
    }

    vector<Student> students(n);
    double total_sum = 0;

    for (int i = 0; i < n; ++i) {
        if (!(cin >> students[i].id)) break;
        
        // Skip the rest of the line after the registration number
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        // Read the name line
        if (!getline(cin, students[i].name)) break;
        
        // Read the grade
        if (!(cin >> students[i].grade)) break;
        
        total_sum += students[i].grade;
    }

    double average = total_sum / (double)n;

    vector<Student> above;
    for (int i = 0; i < n; ++i) {
        // Only students strictly above the average
        if (students[i].grade > average + 1e-9) {
            above.push_back(students[i]);
        }
    }

    // Sorting by Grade (ascending) and ID (ascending) as per sample logic
    sort(above.begin(), above.end(), compareStudents);

    // Print students above average
    for (const auto& s : above) {
        cout << "Matricula: " << s.id 
             << " Nome: " << s.name 
             << " Nota: " << fixed << setprecision(1) << s.grade << "\n";
    }

    // Print final average with 2 decimal places
    cout << "Media = " << fixed << setprecision(2) << average << endl;

    return 0;
}