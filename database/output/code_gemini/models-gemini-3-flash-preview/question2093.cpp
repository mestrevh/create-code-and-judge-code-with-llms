/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    string line;
    getline(cin, line);

    vector<string> ariel, cinderela, pocahontas, jasmine;

    for (int i = 0; i < n; ++i) {
        if (!getline(cin, line)) break;
        if (line.empty()) continue;
        stringstream ss(line);
        string name, taste;
        if (ss >> name) {
            if (ss >> taste) {
                if (taste == "mar" || taste == "mergulho") {
                    ariel.push_back(name);
                } else if (taste == "bailes" || taste == "sapatos") {
                    cinderela.push_back(name);
                } else if (taste == "florestas" || taste == "pacifismo") {
                    pocahontas.push_back(name);
                } else if (taste == "desertos" || taste == "tapetes") {
                    jasmine.push_back(name);
                }
            }
        }
    }

    bool empty = ariel.empty() && cinderela.empty() && pocahontas.empty() && jasmine.empty();

    if (empty) {
        cout << "Infelizmente nao teremos passeios nessa temporada.\n";
    } else {
        if (!ariel.empty()) {
            cout << "Ariel:\n";
            for (const string& s : ariel) cout << "- " << s << "\n";
        }
        if (!cinderela.empty()) {
            cout << "Cinderela:\n";
            for (const string& s : cinderela) cout << "- " << s << "\n";
        }
        if (!pocahontas.empty()) {
            cout << "Pocahontas:\n";
            for (const string& s : pocahontas) cout << "- " << s << "\n";
        }
        if (!jasmine.empty()) {
            cout << "Jasmine:\n";
            for (const string& s : jasmine) cout << "- " << s << "\n";
        }
    }

    return 0;
}