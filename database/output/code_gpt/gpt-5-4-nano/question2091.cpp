/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    string line;
    getline(cin, line);

    map<string, long long> grams;
    vector<string> order;
    long long total = 0;

    auto trim = [](string s) {
        size_t i = 0;
        while (i < s.size() && isspace((unsigned char)s[i])) i++;
        size_t j = s.size();
        while (j > i && isspace((unsigned char)s[j - 1])) j--;
        s = s.substr(i, j - i);
        return s;
    };

    for (int k = 0; k < N; k++) {
        getline(cin, line);
        while (line.empty() && k < N) getline(cin, line);
        line = trim(line);

        size_t pos = line.find(':');
        string op = line.substr(0, pos);
        string name = (pos == string::npos) ? "" : line.substr(pos + 1);
        name = trim(name);

        if (op == "ENTROU") {
            long long q;
            cin >> q;
            getline(cin, line);

            if (grams.find(name) != grams.end()) {
                cout << "Anao ja estava em casa.\n\n";
            } else {
                grams[name] = q;
                order.push_back(name);
                total += q;
                cout << name << " entrou e gostaria de " << q << "g de comida.\n\n";
            }
        } else if (op == "SAIU") {
            if (grams.find(name) == grams.end()) {
                cout << name << " nao estava na casa.\n\n";
            } else {
                grams.erase(name);
                cout << name << " saiu de casa.\n\n";
            }
        }
    }

    int alive = (int)grams.size();
    if (alive == 7) {
        cout << "teoria da branca de neve: porque so ter um se eu posso ter sete?\n";
    }

    vector<string> inside;
    inside.reserve(order.size());
    for (auto &nm : order) {
        if (grams.find(nm) != grams.end()) inside.push_back(nm);
    }

    if (alive != 7) {
        cout << "Estao na casa " << inside.size() << " anoes:\n";
        for (auto &nm : inside) cout << nm << "\n";
    }

    if (alive != 7) {
        cout << total << "\n";
    } else {
        cout << total << "\n";
        for (auto &nm : inside) cout << nm << "\n";
    }

    return 0;
}