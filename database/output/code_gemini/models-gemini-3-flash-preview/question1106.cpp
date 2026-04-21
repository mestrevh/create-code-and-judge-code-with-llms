/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

static string to_upper_str(string s) {
    for (char &c : s) {
        c = (char)toupper((unsigned char)c);
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> mesas[5];
    string name;

    while (cin >> name && name != "-1") {
        int age;
        string team;
        if (!(cin >> age >> team)) break;

        string uname = to_upper_str(name);
        string uteam = to_upper_str(team);

        int target = 4;

        if ((uteam == "FLAMENGO" || uteam == "SPORT" || uteam == "VITORIA") && age >= 30) {
            target = 1;
        } else if ((uteam == "VASCO" || uteam == "TREZE" || uteam == "SANTOS") && age >= 18 && age <= 36) {
            target = 2;
        } else if ((uteam == "BAHIA" || uteam == "FORTALEZA" || uteam == "GREMIO") && age >= 10 && age <= 18) {
            target = 3;
        }

        mesas[target].push_back(uname);
    }

    for (int i = 1; i <= 4; ++i) {
        cout << "MESA " << i << "\n";
        if (mesas[i].empty()) {
            cout << "VAZIA\n";
        } else {
            for (int j = 0; j < (int)mesas[i].size(); ++j) {
                cout << j + 1 << " " << mesas[i][j] << "\n";
            }
        }
        if (i < 4) {
            cout << "\n";
        }
    }

    return 0;
}