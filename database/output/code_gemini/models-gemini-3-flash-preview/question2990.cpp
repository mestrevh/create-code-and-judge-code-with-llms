/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Adventure {
    string name;
    string doctor;
    string local;
    string year;
    vector<string> friends;
    vector<string> enemies;
};

void trim_cr(string& s) {
    while (!s.empty() && (s.back() == '\r' || s.back() == '\n')) {
        s.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<Adventure> database;
    string line;

    while (getline(cin, line)) {
        trim_cr(line);
        if (line == "----------") break;
        if (line.empty()) continue;

        Adventure adv;
        adv.name = line;

        if (!getline(cin, adv.doctor)) break;
        trim_cr(adv.doctor);

        if (!getline(cin, adv.local)) break;
        trim_cr(adv.local);

        if (!getline(cin, adv.year)) break;
        trim_cr(adv.year);

        string dummy;
        if (!getline(cin, dummy)) break; // Marker AMIGOS

        while (getline(cin, line)) {
            trim_cr(line);
            if (line == "INIMIGOS") break;
            adv.friends.push_back(line);
        }

        while (getline(cin, line)) {
            trim_cr(line);
            if (line == "FIM") break;
            adv.enemies.push_back(line);
        }

        database.push_back(adv);
    }

    string b, f, i;
    while (getline(cin, b)) {
        trim_cr(b);
        if (b.empty()) continue;

        if (!getline(cin, f)) break;
        trim_cr(f);

        i = "";
        if (f != "TODOS") {
            if (!getline(cin, i)) break;
            trim_cr(i);
        }

        vector<string> results;
        for (const auto& adv : database) {
            bool match = false;
            if (f == "TODOS") {
                match = true;
            } else if (f == "Aventura") {
                if (adv.name == i) match = true;
            } else if (f == "Doctor") {
                if (adv.doctor == i) match = true;
            } else if (f == "Local") {
                if (adv.local == i) match = true;
            } else if (f == "Ano") {
                if (adv.year == i) match = true;
            } else if (f == "Amigo") {
                for (const auto& fr : adv.friends) {
                    if (fr == i) { match = true; break; }
                }
            } else if (f == "Inimigo") {
                for (const auto& en : adv.enemies) {
                    if (en == i) { match = true; break; }
                }
            }

            if (match) {
                if (b == "Aventura") {
                    results.push_back(adv.name);
                } else if (b == "Doctor") {
                    results.push_back(adv.doctor);
                } else if (b == "Local") {
                    results.push_back(adv.local);
                } else if (b == "Ano") {
                    results.push_back(adv.year);
                } else if (b == "Amigo") {
                    for (const auto& fr : adv.friends) {
                        results.push_back(fr);
                    }
                } else if (b == "Inimigo") {
                    for (const auto& en : adv.enemies) {
                        results.push_back(en);
                    }
                }
            }
        }

        if (results.empty()) {
            cout << "Nao foi possivel encontrar nada com esses parametros.\n\n";
        } else {
            for (const auto& res : results) {
                cout << res << "\n";
            }
            cout << "\n";
        }
    }

    return 0;
}