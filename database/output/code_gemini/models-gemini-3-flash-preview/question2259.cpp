/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Ninja {
    string name;
    int potential;
    bool is_classified;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!getline(cin, s)) return 0;
    while (!s.empty() && (s.back() == '\r' || s.back() == '\n')) {
        s.pop_back();
    }

    int n;
    if (!(cin >> n)) return 0;

    vector<string> names(n);
    vector<int> chakras(n);
    vector<int> jutsus_raw(n);

    for (int i = 0; i < n; ++i) {
        if (!(cin >> names[i] >> chakras[i] >> jutsus_raw[i])) break;
    }

    vector<Ninja> ninjas(n);
    int count_classified = 0;
    bool isInverted = (s == "Esse naruto...");

    for (int i = 0; i < n; ++i) {
        ninjas[i].name = names[i];
        int current_jutsus = isInverted ? jutsus_raw[n - 1 - i] : jutsus_raw[i];
        ninjas[i].potential = chakras[i] - current_jutsus;
        ninjas[i].is_classified = (ninjas[i].potential > 0);
        if (ninjas[i].is_classified) {
            count_classified++;
        }
    }

    sort(ninjas.begin(), ninjas.end(), [](const Ninja& a, const Ninja& b) {
        return a.potential > b.potential;
    });

    for (int i = 0; i < n; ++i) {
        cout << ninjas[i].name << " esta " << (ninjas[i].is_classified ? "classificado(a)" : "desclassificado(a)") << "\n";
    }

    cout << "\n";

    if (count_classified > 0) {
        cout << "Kakashi tera um total de " << count_classified << " aluno(s) nesse semestre" << endl;
    } else {
        cout << "Esse semestre ninguem veio treinar na aldeia da folha" << endl;
    }

    return 0;
}