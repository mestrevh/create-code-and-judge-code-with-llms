/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Aluno {
    string codigo;
    string nome;
    int idade;
    int sexo;
    double enem;
};

struct Disciplina {
    string codigo;
    string nome;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    unordered_map<string, Aluno> alunos;
    alunos.reserve(n * 2);

    for (int i = 0; i < n; i++) {
        Aluno a;
        cin >> a.codigo;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, a.nome);

        string s;
        cin >> a.idade;
        cin >> a.sexo;
        cin >> s;
        a.enem = stod(s);
        alunos[a.codigo] = a;
    }

    int m;
    cin >> m;

    unordered_map<string, Disciplina> disciplinas;
    disciplinas.reserve(m * 2);

    vector<Disciplina> listaDisciplinas;
    listaDisciplinas.reserve(m);

    for (int i = 0; i < m; i++) {
        Disciplina d;
        cin >> d.codigo;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, d.nome);

        disciplinas[d.codigo] = d;
        listaDisciplinas.push_back(d);
    }

    int p;
    cin >> p;

    unordered_map<string, set<string>> matriculas;
    matriculas.reserve(p * 2);

    for (int i = 0; i < p; i++) {
        string codAluno, codDisc;
        cin >> codAluno >> codDisc;
        matriculas[codDisc].insert(codAluno);
    }

    int contMasc = 0, contFem = 0;
    long long somaIdades = 0;
    double somaIdadesEnem = 0.0;
    int contEnem = 0;

    for (const auto &kv : alunos) {
        const Aluno &a = kv.second;
        if (a.sexo == 1) contMasc++;
        else contFem++;
        somaIdades += a.idade;
        if (a.enem > 7.5) {
            somaIdadesEnem += a.idade;
            contEnem++;
        }
    }

    cout << contMasc << "\n";
    cout << contFem << "\n";

    double mediaIdades = n ? (double)somaIdades / n : 0.0;
    cout << fixed << setprecision(2) << mediaIdades << "\n";

    double mediaEnem = contEnem ? somaIdadesEnem / contEnem : 0.0;
    cout << fixed << setprecision(2) << mediaEnem << "\n";

    sort(listaDisciplinas.begin(), listaDisciplinas.end(), [](const Disciplina &x, const Disciplina &y) {
        return x.nome < y.nome;
    });

    for (const auto &d : listaDisciplinas) {
        auto it = matriculas.find(d.codigo);
        if (it == matriculas.end() || it->second.empty()) continue;

        vector<string> nomes;
        nomes.reserve(it->second.size());
        for (const string &codA : it->second) {
            auto ita = alunos.find(codA);
            if (ita != alunos.end()) nomes.push_back(ita->second.nome);
        }
        sort(nomes.begin(), nomes.end());

        cout << d.nome << "\n";
        cout << nomes.size() << "\n";
        for (const string &nm : nomes) cout << nm << "\n";
    }

    return 0;
}