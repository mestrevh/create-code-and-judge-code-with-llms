/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Aluno {
    string nome;
    double nota;
};

struct Turma {
    vector<Aluno> alunos;
};

static Turma lerTurma() {
    Turma t;
    while (true) {
        string nome;
        if (!(cin >> nome)) break;
        if (nome == "*") break;
        double nota;
        cin >> nota;
        t.alunos.push_back({nome, nota});
    }
    return t;
}

static double mediaTurma(const Turma& t) {
    if (t.alunos.empty()) return 0.0;
    double soma = 0.0;
    for (const auto& a : t.alunos) soma += a.nota;
    return soma / t.alunos.size();
}

static optional<Aluno> melhorAluno(const Turma& t) {
    if (t.alunos.empty()) return nullopt;
    const Aluno* best = &t.alunos[0];
    for (const auto& a : t.alunos) if (a.nota > best->nota) best = &a;
    return *best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Turma A = lerTurma();
    Turma B = lerTurma();

    double medA = mediaTurma(A);
    double medB = mediaTurma(B);

    bool vaiA = medA > 8.0;
    bool vaiB = medB > 8.0;

    if (vaiA && vaiB) {
        cout << "Viagem para todos!\n";
    } else if (vaiA) {
        cout << "Viagem para turma A\n";
    } else if (vaiB) {
        cout << "Viagem para turma B\n";
    } else {
        cout << "Nenhuma das turmas viaja...\n";
    }

    optional<Aluno> bestA = melhorAluno(A);
    optional<Aluno> bestB = melhorAluno(B);

    bool ganA = bestA && bestA->nota > 8.0;
    bool ganB = bestB && bestB->nota > 8.0;

    if (!ganA && !ganB) {
        cout << "Ninguem ganhou viagem e ingresso no parque...\n";
        return 0;
    }

    Aluno vencedor;
    if (ganA && ganB) {
        if (bestA->nota > bestB->nota) vencedor = *bestA;
        else vencedor = *bestB;
    } else if (ganA) {
        vencedor = *bestA;
    } else {
        vencedor = *bestB;
    }

    cout << vencedor.nome << " ganhou viagem e ingresso no parque!\n";
    cout << "Nota: " << fixed << setprecision(2) << vencedor.nota << "\n";
    return 0;
}