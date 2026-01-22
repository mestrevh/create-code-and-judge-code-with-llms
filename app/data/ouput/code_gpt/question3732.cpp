/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

int main() {
    while (true) {
        int question_number;
        cin >> question_number;
        if (question_number == 0) break;

        vector<string> options(4);
        for (int i = 0; i < 4; i++) {
            cin >> options[i];
        }

        cout << question_number << ")\n";
        cout << "a)" << options[0] << " c)" << options[1] << "\n";
        cout << "b)" << options[2] << " d)" << options[3] << "\n";
    }
    return 0;
}
