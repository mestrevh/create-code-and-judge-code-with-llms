/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<long long, long long>> phones;
    phones.reserve(15);

    for (int i = 0; i < 15; i++) {
        long long area, number;
        if (!(cin >> area >> number)) return 0;
        phones.push_back({area, number});
    }

    long long desired;
    cin >> desired;

    for (int i = 0; i < 15; i++) {
        cout << "Digite o codigo de area e o telefone:\n";
    }
    cout << "Digite o codigo de area desejado:\n";

    bool found = false;
    for (auto &p : phones) {
        if (p.first == desired) {
            if (!found) {
                cout << "Telefones com o codigo de area " << desired << ":\n";
                found = true;
            }
            cout << p.first << " " << p.second << "\n";
        }
    }

    if (!found) {
        cout << "Nao ha nenhum telefone com o codigo " << desired << "\n";
    }

    return 0;
}