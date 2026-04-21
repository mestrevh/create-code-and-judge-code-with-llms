/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> students;
    int current;
    while (cin >> current && current != -1) {
        students.push_back(current);
    }

    int x;
    if (cin >> x) {
        if (x >= 1 && x <= (int)students.size()) {
            cout << students[x - 1] << "\n";
        }
    }

    return 0;
}