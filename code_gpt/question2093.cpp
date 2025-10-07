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
    int N;
    cin >> N;
    cin.ignore();

    map<string, vector<string>> princesses;
    map<string, string> preferences = {
        {"mar", "Ariel"}, {"mergulho", "Ariel"},
        {"bailes", "Cinderela"}, {"sapatos", "Cinderela"},
        {"florestas", "Pocahontas"}, {"pacifismo", "Pocahontas"},
        {"desertos", "Jasmine"}, {"tapetes", "Jasmine"}
    };

    for (int i = 0; i < N; ++i) {
        string line;
        getline(cin, line);
        size_t space_pos = line.find(' ');
        string name = line.substr(0, space_pos);
        if (space_pos != string::npos) {
            string taste = line.substr(space_pos + 1);
            if (preferences.find(taste) != preferences.end()) {
                princesses[preferences[taste]].push_back(name);
            }
        }
    }

    bool has_output = false;
    for (const string& princess : {"Ariel", "Cinderela", "Pocahontas", "Jasmine"}) {
        if (princesses[princess].size() > 0) {
            cout << princess << ":\n";
            for (const string& name : princesses[princess]) {
                cout << "- " << name << '\n';
            }
            has_output = true;
        }
    }

    if (!has_output) {
        cout << "Infelizmente nao teremos passeios nessa temporada." << endl;
    }

    return 0;
}
