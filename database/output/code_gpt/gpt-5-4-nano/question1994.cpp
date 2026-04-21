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

    double sum = 0.0;
    vector<string> lastNames(N + 1);
    vector<char> status(N + 1);
    vector<int> absences(N + 1);
    vector<double> grades(N + 1);

    for (int i = 1; i <= N; i++) {
        string reg, first, last;
        double media;
        int faltas;
        char st;
        cin >> reg >> first >> last >> media >> faltas >> st;
        lastNames[i] = last;
        status[i] = st;
        absences[i] = faltas;
        grades[i] = media;
        sum += media;
    }

    double avg = sum / N;
    int limit = (int)floor(0.10 * N);

    vector<int> destacados;
    for (int i = 1; i <= N; i++) {
        if (grades[i] > avg && status[i] == 'M' && absences[i] < limit) {
            destacados.push_back(i);
        }
    }

    for (size_t k = 0; k < destacados.size(); k++) {
        int pos = destacados[k];
        cout << pos << ":" << lastNames[pos];
        if (k + 1 < destacados.size()) cout << "\n";
    }

    return 0;
}