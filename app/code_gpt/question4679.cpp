/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
    string name;
    int class_num;
    map<int, vector<string>> classes;

    while (getline(cin, name)) {
        if (getline(cin, name) && cin >> class_num) {
            cin.ignore(); // clear newline
            classes[class_num].push_back(name);
        }
    }

    for (int i = 1; i <= 3; ++i) {
        cout << "Turma " << i << ":\n";
        for (const auto& student : classes[i]) {
            cout << student << endl;
        }
        cout << endl;
    }

    return 0;
}
