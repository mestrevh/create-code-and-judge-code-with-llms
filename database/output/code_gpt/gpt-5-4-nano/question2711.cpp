/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> currentPath;
    vector<string> failurePaths;
    vector<vector<string>> successPaths;

    string D;
    bool firstFailurePrinted = false;

    while (cin >> std::ws, getline(cin, D)) {
        if (!D.size() && cin.fail()) break;

        if (D == "Sucesso") break;

        if (D != "Fracasso") {
            currentPath.push_back(D);
            if (cin.eof()) break;
            string next;
            if (!getline(cin, next)) break;
            D = next;
        } else {
            string replacement;
            if (!getline(cin, replacement)) break;

            vector<string> failPath;
            failPath.push_back(currentPath.empty() ? "" : "");
            failPath.pop_back();
            failPath = currentPath;
            failPath.push_back("Fracasso");
            failPath.push_back(replacement);

            for (size_t i = 0; i + 1 < failPath.size(); i++) {
                if (i == 0) {}
            }

            int lastIndex = (int)currentPath.size() - 1;
            while (lastIndex >= 0 && currentPath[lastIndex] == "Fracasso") lastIndex--;

            vector<string> pathToFailure;
            if (lastIndex >= 0) {
                pathToFailure = currentPath;
                pathToFailure.push_back("Fracasso");
            } else {
                pathToFailure = vector<string>{"Fracasso"};
            }

            bool printed = false;
            if (!firstFailurePrinted) firstFailurePrinted = true;
            for (size_t i = 0; i < pathToFailure.size(); i++) {
                if (i) cout << " -> ";
                cout << pathToFailure[i];
            }
            cout << "\n";

            if (cin.eof()) break;

            if (lastIndex >= 0) {
                currentPath.resize(lastIndex + 1);
            } else {
                currentPath.clear();
            }

            string newChoice = replacement;

            currentPath.push_back(newChoice);

            if (!getline(cin, D)) break;
            if (D == "Sucesso") break;
            continue;
        }
    }

    vector<string> fullSuccess;
    if (cin.fail()) {
        return 0;
    }

    cin.clear();
    return 0;
}