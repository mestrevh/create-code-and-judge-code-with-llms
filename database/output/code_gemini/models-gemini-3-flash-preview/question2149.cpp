/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <list>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string courses[] = {"Algoritmo", "SD", "Fisica", "Logica", "Estatistica"};
    list<string> enrollment[5];

    string line;
    // Stage 1: Enrollment Processing
    while (getline(cin, line)) {
        if (line.empty() || line.find_first_not_of(" \t\n\r") == string::npos) {
            break;
        }
        stringstream ss(line);
        string cName, sName;
        if (!(ss >> cName >> sName)) break;
        
        for (int i = 0; i < 5; ++i) {
            if (cName == courses[i]) {
                bool found = false;
                for (const string& name : enrollment[i]) {
                    if (name == sName) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    enrollment[i].push_back(sName);
                }
                break;
            }
        }
    }

    // Stage 2: Cancellation Processing
    while (getline(cin, line)) {
        if (line.empty() || line.find_first_not_of(" \t\n\r") == string::npos) {
            continue;
        }
        stringstream ss(line);
        string cName, sName;
        if (!(ss >> cName >> sName)) continue;

        for (int i = 0; i < 5; ++i) {
            if (cName == courses[i]) {
                for (auto it = enrollment[i].begin(); it != enrollment[i].end(); ++it) {
                    if (*it == sName) {
                        enrollment[i].erase(it);
                        break;
                    }
                }
                break;
            }
        }
    }

    // Output formatting according to specifications
    for (int i = 0; i < 5; ++i) {
        cout << "Estao matriculados na turma de " << courses[i] << " " << enrollment[i].size() << " aluno(os)\n";
    }

    return 0;
}