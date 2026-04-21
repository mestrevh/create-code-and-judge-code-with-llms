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
        string line;
        cin >> ws;
        getline(cin, line);
        size_t p1 = line.find('-');
        size_t p2 = (p1 == string::npos) ? string::npos : line.find('-', p1 + 1);

        int matricula = stoi(line.substr(0, p1));
        string nome = line.substr(p1 + 1, p2 - (p1 + 1));
        double nota = stod(line.substr(p2 + 1));

        alunos.push_back({matricula, nome, nota});
    }

    double soma = 0.0;
    for (auto &a : alunos) soma += a.nota;
    double media = soma / N;

    vector<Aluno> abaixo, acima;
    for (auto &a : alunos) {
        if (a.nota < media) abaixo.push_back(a);
        else acima.push_back(a);
    }

    auto cmp = [](const Aluno& x, const Aluno& y) {
        if (x.nota != y.nota) return x.nota < y.nota;
        return x.matricula < y.matricula;
    };

    sort(abaixo.begin(), abaixo.end(), cmp);
    sort(acima.begin(), acima.end(), cmp);

    cout << "Alunos abaixo da media:\n";
    cout.setf(std::ios::fixed);
    cout << setprecision(1);
    for (auto &a : abaixo) {
        cout << "Matricula: " << a.matricula << " Nome: " << a.nome << " Nota: " << a.nota << "\n";
    }

    cout << "Alunos iguais ou acima da media:\n";
    for (auto &a : acima) {
        cout << "Matricula: " << a.matricula << " Nome: " << a.nome << " Nota: " << a.nota << "\n";
    }

    cout << setprecision(2) << "Media = " << media << "\n";
    return 0;
}