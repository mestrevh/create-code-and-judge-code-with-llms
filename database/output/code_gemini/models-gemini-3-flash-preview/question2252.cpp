/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

struct Student {
    string name;
    double avg;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    string dummy;
    getline(cin, dummy);

    vector<Student> students;
    students.reserve(n);

    for (int i = 0; i < n; ++i) {
        string line;
        if (!getline(cin, line)) break;
        if (line.empty()) {
            continue;
        }

        size_t firstComma = line.find(',');
        string name;
        vector<double> notes;
        if (firstComma == string::npos) {
            name = line;
        } else {
            name = line.substr(0, firstComma);
            string notesPart = line.substr(firstComma + 1);
            stringstream ss(notesPart);
            string note;
            while (getline(ss, note, ',')) {
                notes.push_back(atof(note.c_str()));
            }
        }

        vector<double> v(3, 0.0);
        for (int j = 0; j < 3 && j < (int)notes.size(); ++j) {
            v[j] = notes[j];
        }

        if (notes.size() >= 4) {
            double mn = v[0];
            int minIdx = 0;
            if (v[1] < mn) {
                mn = v[1];
                minIdx = 1;
            }
            if (v[2] < mn) {
                mn = v[2];
                minIdx = 2;
            }
            
            if (notes[3] > mn) {
                v[minIdx] = notes[3];
            }
        }

        double sum = v[0] + v[1] + v[2];
        students.push_back({name, sum / 3.0});
    }

    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        if (abs(a.avg - b.avg) > 1e-9) {
            return a.avg < b.avg;
        }
        return a.name < b.name;
    });

    for (const auto& s : students) {
        cout << s.name << " " << fixed << setprecision(2) << s.avg << "\n";
    }

    return 0;
}