/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Aluno {
    string nome;
    double n1, n2, n3;
};

double media(const Aluno& a) {
    return (a.n1 + a.n2 + a.n3) / 3.0;
}

string situacao(double m) {
    if (m >= 7.0) return "Aprovado";
    if (m >= 4.0) return "Final";
    return "Reprovado";
}

void ordenar(vector<Aluno>& v) {
    sort(v.begin(), v.end(), [](const Aluno& a, const Aluno& b) {
        return a.nome < b.nome;
    });
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<Aluno> v(n);
    for (int i = 0; i < n; i++) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, v[i].nome);
        cin >> v[i].n1 >> v[i].n2 >> v[i].n3;
    }

    ordenar(v);

    cout.setf(ios::fixed);
    cout << setprecision(2);

    for (int i = 0; i < n; i++) {
        double m = media(v[i]);
        cout << "Aluno: " << v[i].nome << "\n";
        cout << "Media: " << m << "\n";
        cout << "Situacao: " << situacao(m);
        if (i + 1 < n) cout << "\n\n";
    }

    return 0;
}