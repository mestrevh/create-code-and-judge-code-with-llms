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

    vector<long long> a(n, 0);
    long long totalExpulsos = 0;
    long long fraseCount = 0;

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        bool possuiMonitorLigado = false;
        for (int j = 0; j < m; j++) {
            long long v;
            cin >> v;
            if (v > 0) possuiMonitorLigado = true;
        }
        if (possuiMonitorLigado) {
            fraseCount++;
        }
        a[i] = fraseCount;
        if (possuiMonitorLigado) {
            cin.clear();
        }
        if (m == 0) a[i] = fraseCount;
    }

    cin.clear();
    cin.seekg(0, ios::beg);

    cin >> n;

    fraseCount = 0;
    totalExpulsos = 0;

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        vector<long long> vals(m);
        for (int j = 0; j < m; j++) cin >> vals[j];

        bool possuiMonitorLigado = false;
        for (auto v : vals) if (v > 0) { possuiMonitorLigado = true; break; }

        if (possuiMonitorLigado) {
            fraseCount++;
            for (auto v : vals) {
                if (v > 0) {
                    long long sobra = v - fraseCount;
                    if (sobra > 0) totalExpulsos++;
                }
            }
        }
    }

    cout << "Pessoal, vai ter aula de IP aqui agora\n";
    for (long long i = 0; i < fraseCount; i++) {
        cout << "Desliga o monitor...\n";
    }
    if (totalExpulsos > 0) {
        cout << "Sergio pistolou e expulsou " << totalExpulsos << " aluno(s) do laboratorio.\n";
    }
    return 0;
}