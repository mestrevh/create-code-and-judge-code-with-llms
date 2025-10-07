/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();

    unordered_map<string, vector<string>> birthdays;
    const string months[] = {"", "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

    for (int i = 0; i < N; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string name;
        int day, month;

        ss >> name >> day >> month;
        string key = to_string(day) + "_" + to_string(month);
        birthdays[key].push_back(name);
    }

    bool found = false;

    for (const auto& entry : birthdays) {
        if (entry.second.size() > 1) {
            found = true;
            int day = stoi(entry.first.substr(0, entry.first.find('_')));
            int month = stoi(entry.first.substr(entry.first.find('_') + 1));
            cout << "Dia " << day << " de " << months[month] << ": ";

            sort(entry.second.begin(), entry.second.end());
            for (size_t j = 0; j < entry.second.size(); j++) {
                cout << entry.second[j];
                if (j < entry.second.size() - 1) cout << ", ";
            }
            cout << endl;
        }
    }
    
    if (!found) {
        cout << "Ninguem faz aniversario no mesmo dia" << endl;
    }

    return 0;
}
