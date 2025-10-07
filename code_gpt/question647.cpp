/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    while (cin >> N && N != 0) {
        vector<int> history;
        int totalPresses = 0;

        for (int i = 0; i < N; ++i) {
            int command;
            cin >> command;

            if (command <= history.size()) {
                totalPresses += history.size() - command + 1;
            } else {
                totalPresses += command;
            }

            history.insert(history.begin() + (command - 1), command);
        }

        cout << totalPresses << endl;
    }
    return 0;
}
