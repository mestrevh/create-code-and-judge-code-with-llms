/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> names;
    vector<long long> ids;

    string name;
    long long id;
    while (cin >> name >> id) {
        names.push_back(name);
        ids.push_back(id);
    }

    int n = (int)names.size();
    int i = 0;
    int pos = 0;

    while (i < n) {
        long long target = ids[i];
        int partnerIndex = -1;
        for (int j = i + 1; j < n; j++) {
            if (ids[j] == target) {
                partnerIndex = j;
                break;
            }
        }

        if (partnerIndex != -1) {
            cout << names[i] << " seu parceiro esta na posicao " << partnerIndex
                 << " e o seu nome e " << names[partnerIndex] << ".";
            i += 2;
        } else {
            cout << names[i] << " nao existe um parceiro para voce.";
            i += 1;
        }

        if (i <= n) cout << "\n";
        pos++;
    }

    return 0;
}