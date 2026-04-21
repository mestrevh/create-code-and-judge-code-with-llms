/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const int PROG2_SIZE = 45;
    const int PROG3_SIZE = 30;

    vector<int> prog2(PROG2_SIZE);
    for (int i = 0; i < PROG2_SIZE; ++i) {
        cin >> prog2[i];
    }

    unordered_set<int> prog3_set;
    for (int i = 0; i < PROG3_SIZE; ++i) {
        int student_id;
        cin >> student_id;
        prog3_set.insert(student_id);
    }

    bool first = true;
    for (int i = 0; i < PROG2_SIZE; ++i) {
        if (prog3_set.find(prog2[i]) != prog3_set.end()) {
            cout << prog2[i] << " ";
        }
    }
    cout << "\n";

    return 0;
}

