/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Aluno {
    string nome;
    int matricula;
    int idade;
    double nota;
};

void bubbleSortIdade(vector<Aluno>& a) {
    int n = (int)a.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j].idade > a[j + 1].idade) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void selectionSortNota(vector<Aluno>& a) {
    int n = (int)a.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j].nota < a[minIdx].nota) minIdx = j;
        }
        if (minIdx != i) swap(a[i], a[minIdx]);
    }
}

void insertionSortMatricula(vector<Aluno>& a) {
    int n = (int)a.size();
    for (int i = 1; i < n; i++) {
        Aluno key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j].matricula > key.matricula) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void printLista(const vector<Aluno>& a, const string& criterio) {
    cout << "ordenado por " << criterio << ":\n";
    cout << fixed << setprecision(2);
    for (const auto& x : a) {
        cout << x.nome << ' ' << x.matricula << ' ' << x.idade << ' ' << x.nota << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Aluno> alunos;
    int cmd;
    while (cin >> cmd) {
        if (cmd == 0) break;
        if (cmd == 1) {
            Aluno a;
            cin >> a.nome >> a.matricula >> a.idade >> a.nota;
            alunos.push_back(a);
        } else if (cmd == 2) {
            bubbleSortIdade(alunos);
            printLista(alunos, "idade");
        } else if (cmd == 3) {
            selectionSortNota(alunos);
            printLista(alunos, "nota");
        } else if (cmd == 4) {
            insertionSortMatricula(alunos);
            printLista(alunos, "matricula");
        }
    }
    return 0;
}