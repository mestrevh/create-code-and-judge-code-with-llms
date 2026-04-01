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

    int n;
    if (!(cin >> n)) return 0;
    
    string dummy;
    getline(cin, dummy);

    vector<string> goals(n);
    for (int i = 0; i < n; ++i) {
        getline(cin, goals[i]);
    }

    int m;
    if (!(cin >> m)) {
        m = 0;
    } else {
        getline(cin, dummy);
    }

    vector<string> completed(m);
    for (int i = 0; i < m; ++i) {
        getline(cin, completed[i]);
    }

    vector<string> missing;
    for (int i = 0; i < n; ++i) {
        bool found = false;
        for (int j = 0; j < m; ++j) {
            if (goals[i] == completed[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            missing.push_back(goals[i]);
        }
    }

    if (missing.empty()) {
        cout << "Smelly Cat, Smelly Cat, what are they feeding you?" << endl;
    } else {
        cout << "Ainda falta(m) " << missing.size() << " objetivo(s)!" << endl;
        for (const string& s : missing) {
            cout << s << endl;
        }
    }

    return 0;
}