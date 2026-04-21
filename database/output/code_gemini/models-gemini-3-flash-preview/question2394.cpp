/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string command;
    vector<int> stack;

    while (cin >> command && command != "Fim") {
        if (command == "Empilhar") {
            int value;
            if (cin >> value) {
                stack.push_back(value);
            }
        } else if (command == "Desempilhar") {
            if (!stack.empty()) {
                stack.pop_back();
            }
        }

        for (size_t i = stack.size(); i > 0; --i) {
            cout << stack[i - 1] << (i == 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}