/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Student {
    string name;
    int monitorID;
    int scores[9];
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A;
    if (!(cin >> A)) return 0;

    map<int, string> monitors;
    for (int i = 0; i < A; ++i) {
        string monitorName;
        int monitorID;
        if (cin >> monitorName >> monitorID) {
            monitors[monitorID] = monitorName;
        }
    }

    int B;
    if (!(cin >> B)) return 0;

    vector<Student> students(B);
    for (int i = 0; i < B; ++i) {
        cin >> students[i].name >> students[i].monitorID;
    }

    for (int i = 0; i < B; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> students[i].scores[j];
        }
    }

    int N;
    if (!(cin >> N)) return 0;

    for (int i = 0; i < B; ++i) {
        int totalPoints = 0;
        for (int j = 0; j < 9; ++j) {
            totalPoints += students[i].scores[j];
        }

        // Bonus logic: question 3 of list N receives an extra point if completed.
        // List N questions are at indices: 3*(N-1), 3*(N-1)+1, 3*(N-1)+2
        // Question 3 of list N is at index 3*N - 1.
        if (N >= 1 && N <= 3) {
            if (students[i].scores[3 * N - 1] == 1) {
                totalPoints += 1;
            }
        }

        cout << students[i].name << "\n";
        if (monitors.count(students[i].monitorID)) {
            cout << monitors[students[i].monitorID] << "\n";
        }
        cout << totalPoints << "\n";
    }

    return 0;
}