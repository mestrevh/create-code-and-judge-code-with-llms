/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Aluno {
    int matricula;
    string nome;
    double nota;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<Aluno> alunos;
    alunos.reserve(N);

    for (int i = 0; i < N; i++) {
        int matricula;
        string nome;
        double nota;
        cin >> matricula >> ws;
        getline(cin, nome);
        cin >> nota;
        alunos.push_back({matricula, nome, nota});
    }

    double soma = 0.0;
    for (const auto& a : alunos) soma += a.nota;
    double media = soma / N;

    vector<Aluno> acima;
    for (const auto& a : alunos) {
        if (a.nota > media) acima.push_back(a);
    }

    sort(acima.begin(), acima.end(), [](const Aluno& x, const Aluno& y) {
        if (x.nota != y.nota) return x.nota > y.nota;
        return x.matricula < y.matricula;
    });

    cout.setf(std::ios::fixed);
    cout << setprecision(2);

    cout.unsetf(std::ios::fixed);
    cout << setprecision(10);

    for (const auto& a : acima) {
        cout << "Matricula: " << a.matricula << " Nome: " << a.nome << " Nota: ";
        cout << a.nota;
        cout << "\n";
    }

    cout.setf(std::ios::fixed);
    cout << setprecision(2);
    cout << "Media = " << media << "\n";

    return 0;
}