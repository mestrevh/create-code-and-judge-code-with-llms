/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Character {
    string name;
    int health;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Character> characters(n);
    for (int i = 0; i < n; ++i) {
        if (!(cin >> characters[i].name >> characters[i].health)) break;
    }

    int idx;
    while (cin >> idx && idx != -1) {
        int change;
        if (!(cin >> change)) break;

        if (idx < 0 || idx >= (int)characters.size()) {
            cout << "indice invalido" << "\n";
        } else {
            characters[idx].health += change;
            for (const auto& c : characters) {
                cout << c.name << " = " << c.health << "\n";
            }
        }
    }

    return 0;
}