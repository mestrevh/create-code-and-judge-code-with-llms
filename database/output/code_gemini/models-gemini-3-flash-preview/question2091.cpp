/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <list>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    string line;
    getline(cin, line); 

    list<string> house;
    unordered_map<string, pair<long long, list<string>::iterator>> dwarves;
    long long total_food = 0;

    for (int i = 0; i < n; ) {
        if (!getline(cin, line)) break;
        if (line.empty()) continue;

        size_t pos = line.find(':');
        if (pos == string::npos) continue;

        string op = line.substr(0, pos);
        string name = line.substr(pos + 1);
        i++;

        if (op == "ENTROU") {
            long long q;
            if (!(cin >> q)) break;
            string temp;
            getline(cin, temp); 
            if (dwarves.find(name) != dwarves.end()) {
                cout << "Anao ja estava em casa.\n";
            } else {
                cout << name << " entrou e gostaria de " << q << "g de comida.\n";
                house.push_back(name);
                dwarves[name] = {q, --house.end()};
                total_food += q;
            }
        } else if (op == "SAIU") {
            if (dwarves.find(name) != dwarves.end()) {
                cout << name << " saiu de casa.\n";
                total_food -= dwarves[name].first;
                house.erase(dwarves[name].second);
                dwarves.erase(name);
            } else {
                cout << name << " nao estava na casa.\n";
            }
        }
    }

    cout << "\n";
    if (house.size() == 7) {
        cout << "teoria da branca de neve: porque so ter um se eu posso ter sete?\n";
    } else {
        cout << "Estao na casa " << house.size() << " anoes:\n";
    }

    for (const string& s : house) {
        cout << s << "\n";
    }
    cout << total_food << endl;

    return 0;
}