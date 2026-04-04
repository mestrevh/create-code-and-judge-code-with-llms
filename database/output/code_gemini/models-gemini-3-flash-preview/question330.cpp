/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Student {
    string id;
    string name;
    int age;
    int sex;
    double enem;
};

struct Discipline {
    string id;
    string name;
    vector<string> enrolledNames;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    string dummy;
    getline(cin, dummy);

    map<string, Student> studentsById;
    int maleCount = 0;
    int femaleCount = 0;
    double totalAgeSum = 0;
    double enemHighAgeSum = 0;
    int enemHighCount = 0;

    for (int i = 0; i < n; ++i) {
        Student s;
        string line;
        getline(cin, s.id);
        getline(cin, s.name);
        getline(cin, line);
        s.age = stoi(line);
        getline(cin, line);
        s.sex = stoi(line);
        getline(cin, line);
        s.enem = stod(line);

        studentsById[s.id] = s;

        if (s.sex == 1) maleCount++;
        else if (s.sex == 0) femaleCount++;

        totalAgeSum += s.age;
        if (s.enem > 7.5) {
            enemHighAgeSum += s.age;
            enemHighCount++;
        }
    }

    cout << maleCount << "\n";
    cout << femaleCount << "\n";
    cout << fixed << setprecision(2) << (n > 0 ? (double)totalAgeSum / n : 0.00) << "\n";
    cout << fixed << setprecision(2) << (enemHighCount > 0 ? (double)enemHighAgeSum / enemHighCount : 0.00) << "\n";

    int m;
    if (cin >> m) {
        getline(cin, dummy);
        vector<Discipline> discVec;
        map<string, int> discIdToIndex;

        for (int i = 0; i < m; ++i) {
            Discipline d;
            getline(cin, d.id);
            getline(cin, d.name);
            discIdToIndex[d.id] = i;
            discVec.push_back(d);
        }

        int p;
        if (cin >> p) {
            for (int i = 0; i < p; ++i) {
                string sid, did;
                cin >> sid >> did;
                if (discIdToIndex.count(did) && studentsById.count(sid)) {
                    discVec[discIdToIndex[did]].enrolledNames.push_back(studentsById[sid].name);
                }
            }
        }

        sort(discVec.begin(), discVec.end(), [](const Discipline& a, const Discipline& b) {
            return a.name < b.name;
        });

        for (auto& d : discVec) {
            cout << d.name << "\n";
            cout << d.enrolledNames.size() << "\n";
            sort(d.enrolledNames.begin(), d.enrolledNames.end());
            for (const auto& studentName : d.enrolledNames) {
                cout << studentName << "\n";
            }
        }
    }

    return 0;
}