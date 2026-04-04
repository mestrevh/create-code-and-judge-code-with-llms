/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <sstream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string firstLine;
    if (!getline(cin, firstLine)) return 0;
    while (!firstLine.empty() && (firstLine.back() == '\r' || firstLine.back() == '\n')) {
        firstLine.pop_back();
    }

    unordered_set<string> enemies;
    if (firstLine.find(',') != string::npos) {
        stringstream ss(firstLine);
        string seg;
        while (getline(ss, seg, ',')) {
            size_t f = seg.find_first_not_of(" \t");
            if (f != string::npos) {
                size_t l = seg.find_last_not_of(" \t");
                enemies.insert(seg.substr(f, l - f + 1));
            }
        }
    } else {
        stringstream ss(firstLine);
        string word;
        while (ss >> word) {
            enemies.insert(word);
        }
    }

    list<string> tardis_list;
    unordered_map<string, list<string>::iterator> tardis_map;

    string line;
    while (getline(cin, line)) {
        while (!line.empty() && (line.back() == '\r' || line.back() == '\n')) {
            line.pop_back();
        }
        if (line.empty()) continue;

        size_t cmdStart = line.find_first_not_of(" \t");
        if (cmdStart == string::npos) continue;
        size_t cmdEnd = line.find_first_of(" \t", cmdStart);
        
        string cmd, name = "";
        if (cmdEnd == string::npos) {
            cmd = line.substr(cmdStart);
        } else {
            cmd = line.substr(cmdStart, cmdEnd - cmdStart);
            string rawName = line.substr(cmdEnd + 1);
            size_t f = rawName.find_first_not_of(" \t");
            if (f != string::npos) {
                size_t l = rawName.find_last_not_of(" \t");
                name = rawName.substr(f, l - f + 1);
            }
        }

        if (cmd == "ENTRAR") {
            if (enemies.count(name)) {
                cout << "Doctor o vilao " << name << " tentou entrar na Tardis." << endl;
            } else {
                if (tardis_map.find(name) == tardis_map.end()) {
                    tardis_list.push_back(name);
                    tardis_map[name] = --tardis_list.end();
                }
                cout << name << " entrou na Tardis." << endl;
            }
        } else if (cmd == "SAIR") {
            if (tardis_map.count(name)) {
                tardis_list.erase(tardis_map[name]);
                tardis_map.erase(name);
                cout << name << " saiu da Tardis." << endl;
            } else {
                cout << name << " nao esta na Tardis." << endl;
            }
        } else if (cmd == "VERIFICAR" || cmd == "Verificar") {
            if (tardis_map.count(name)) {
                cout << name << " esta na Tardis." << endl;
            } else {
                cout << name << " nao esta na Tardis." << endl;
            }
        } else if (cmd == "LISTAR") {
            if (tardis_list.empty()) {
                cout << "Nao ha ninguem na Tardis no momento." << endl;
            } else {
                for (const string& p : tardis_list) {
                    cout << p << endl;
                }
            }
        }
    }

    return 0;
}