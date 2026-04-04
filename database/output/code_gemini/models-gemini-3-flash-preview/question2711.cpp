/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printPath(const vector<string>& path, const string& last) {
    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i] << " -> ";
    }
    cout << last << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string D;
    vector<string> path;
    vector<int> failed_count;

    while (getline(cin, D)) {
        if (D.empty()) continue;
        if (!D.empty() && D.back() == '\r') {
            D.pop_back();
        }
        if (D.empty()) continue;

        if (D == "Fracasso") {
            printPath(path, "Fracasso");
            if (!failed_count.empty()) {
                failed_count.back()++;
                while (!failed_count.empty() && failed_count.back() == 2) {
                    path.pop_back();
                    failed_count.pop_back();
                    if (!failed_count.empty()) {
                        failed_count.back()++;
                    }
                }
            }
        } else if (D == "Sucesso") {
            printPath(path, "Sucesso");
            break;
        } else {
            path.push_back(D);
            failed_count.push_back(0);
        }
    }

    return 0;
}