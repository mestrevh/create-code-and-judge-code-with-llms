/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!getline(cin, s)) return 0;
    while(s.size() && (s.back()=='\r' || s.back()=='\n')) s.pop_back();

    int N;
    if (!(cin >> N)) return 0;

    vector<string> name(N);
    vector<long long> chakra(N);
    vector<long long> jutsusInput(N);

    for (int i = 0; i < N; i++) {
        cin >> name[i] >> chakra[i] >> jutsusInput[i];
    }

    vector<long long> jutsus(N);
    if (s.find("Tudo certo") != string::npos) {
        for (int i = 0; i < N; i++) jutsus[i] = jutsusInput[i];
    } else {
        for (int i = 0; i < N; i++) jutsus[i] = jutsusInput[N - 1 - i];
    }

    vector<pair<long long,int>> pot(N);
    for (int i = 0; i < N; i++) {
        pot[i] = {chakra[i] - jutsus[i], i};
    }

    sort(pot.begin(), pot.end(), [](const auto& a, const auto& b){
        return a.first > b.first;
    });

    int classified = 0;
    for (int k = 0; k < N; k++) {
        int i = pot[k].second;
        long long p = pot[k].first;
        if (p > 0) {
            cout << name[i] << " esta classificado(a)\n";
            classified++;
        } else {
            cout << name[i] << " esta desclassificado(a)\n";
        }
    }

    cout << "\n";
    if (classified > 0) {
        cout << "Kakashi tera um total de " << classified << " aluno(s) nesse semestre\n";
    } else {
        cout << "Esse semestre ninguem veio treinar na aldeia da folha\n";
    }

    return 0;
}