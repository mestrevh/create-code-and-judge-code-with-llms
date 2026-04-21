/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    string dummy;
    getline(cin, dummy);

    list<string> chain;
    for (int i = 0; i < n; ++i) {
        string disc;
        if (getline(cin, disc)) {
            if (!disc.empty() && disc.back() == '\r') disc.pop_back();
            chain.push_back(disc);
        }
    }

    string query;
    while (getline(cin, query)) {
        if (query.empty()) continue;
        if (query.back() == '\r') query.pop_back();

        int pos = 0;
        bool found = false;
        auto it = chain.begin();
        while (it != chain.end()) {
            if (*it == query) {
                found = true;
                break;
            }
            ++it;
            ++pos;
        }

        if (!found) {
            cout << query << " nao pode ser cursada nessa cadeia de pre-requisitos.\n";
        } else if (pos == 0) {
            cout << query << " podera ser cursada esse periodo.\n";
        } else {
            cout << query << " podera ser cursada depois de " << pos << " periodos, depois de ter passado por: ";
            auto it2 = chain.begin();
            for (int j = 0; j < pos; ++j, ++it2) {
                cout << *it2;
                if (j < pos - 2) {
                    cout << ", ";
                } else if (j == pos - 2) {
                    cout << " e ";
                }
            }
            cout << ".\n";
        }
    }

    return 0;
}