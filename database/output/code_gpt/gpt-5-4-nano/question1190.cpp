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

    for (int i = 0; i < N; i++) {
        string full;
        getline(cin, full);
        if (full.empty()) { i--; continue; }

        size_t lastSpace = full.find_last_of(' ');
        string firstName = (lastSpace == string::npos) ? full : full.substr(0, lastSpace);
        string family = (lastSpace == string::npos) ? "" : full.substr(lastSpace + 1);

        cout << "Cara familia " << family << ", sentimos muito pela tragica morte de " << firstName << ".\n";

        if (family == "Lannister") {
            cout << "Os campos agora o ouvirao rugir.\n";
        } else if (family == "Stark") {
            cout << "O inverno chega para todos.\n";
        } else if (family == "Targaryen") {
            cout << "Voces sao superestimados mesmo.\n";
        }
    }
    return 0;
}