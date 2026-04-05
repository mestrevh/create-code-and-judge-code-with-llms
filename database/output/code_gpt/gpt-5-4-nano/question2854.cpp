/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Digite as matriculas dos alunos de Introducao a Programacao:";
    vector<long long> intro(45);
    for (int i = 0; i < 45; i++) {
        if (!(cin >> intro[i])) return 0;
    }

    cout << "Digite as matriculas dos alunos de Laboratorio de Programacao:";
    vector<long long> lab(30);
    for (int i = 0; i < 30; i++) cin >> lab[i];

    unordered_set<long long> s;
    s.reserve(64);
    for (auto x : lab) s.insert(x);

    cout << "Alunos matriculados em ambas as disciplinas:";
    bool first = true;
    for (auto x : intro) {
        if (s.find(x) != s.end()) {
            if (!first) cout << ' ';
            cout << x;
            first = false;
        }
    }
    return 0;
}