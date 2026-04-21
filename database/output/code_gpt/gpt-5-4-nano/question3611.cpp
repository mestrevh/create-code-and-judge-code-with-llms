/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    struct Contact {
        string name;
        string number;
        int code;
    };

    vector<Contact> contacts;
    contacts.reserve(n);

    for (int i = 0; i < n; i++) {
        string name;
        getline(cin >> ws, name);
        string number;
        getline(cin, number);
        int code;
        cin >> code;
        contacts.push_back({name, number, code});
        string dummy;
        getline(cin, dummy);
    }

    auto vinculo = [](int c) -> string {
        if (c == 1) return "Familia";
        if (c == 2) return "Faculdade";
        return "Amigo";
    };

    vector<string> queries;
    while (true) {
        string q;
        if (!(cin >> q)) break;
        if (q == "#") break;
        queries.push_back(q);
    }

    bool firstOutput = true;
    for (const string& q : queries) {
        vector<const Contact*> matches;
        for (const auto& ct : contacts) {
            string firstName;
            {
                istringstream iss(ct.name);
                iss >> firstName;
            }
            if (firstName == q) matches.push_back(&ct);
        }

        if (!matches.empty()) {
            for (const auto* ct : matches) {
                if (!firstOutput) cout << "\n\n";
                firstOutput = false;
                cout << "Nome: " << ct->name << "\n";
                cout << "Numero: " << ct->number << "\n";
                cout << "Vinculo: " << vinculo(ct->code);
            }
        } else {
            if (!firstOutput) cout << "\n\n";
            firstOutput = false;
            cout << q << " nao foi cadastrado";
        }
    }

    return 0;
}