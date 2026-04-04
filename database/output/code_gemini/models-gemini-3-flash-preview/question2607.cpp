/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    string monthNames[] = {
        "",
        "Janeiro",
        "Fevereiro",
        "Marco",
        "Abril",
        "Maio",
        "Junho",
        "Julho",
        "Agosto",
        "Setembro",
        "Outubro",
        "Novembro",
        "Dezembro"
    };

    // Use a map of pairs to keep dates sorted chronologically (Month, Day)
    map<pair<int, int>, vector<string>> groups;

    for (int i = 0; i < N; ++i) {
        string name;
        int d, m;
        if (!(cin >> name >> d >> m)) break;
        groups[{m, d}].push_back(name);
    }

    bool found = false;
    for (auto const& [date, names] : groups) {
        if (names.size() > 1) {
            found = true;
            // The output format from the test case includes "Dia " at the start
            cout << "Dia " << date.second << " de " << monthNames[date.first] << ": ";
            for (size_t i = 0; i < names.size(); ++i) {
                cout << names[i];
                if (i < names.size() - 1) {
                    cout << ", ";
                }
            }
            cout << "\n";
        }
    }

    if (!found) {
        cout << "Ninguem faz aniversario no mesmo dia" << endl;
    }

    return 0;
}