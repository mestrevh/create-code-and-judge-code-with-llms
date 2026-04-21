/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Aluno {
    string nome;
    int matricula;
    int idade;
    double nota;
};

void bubbleSort(vector<Aluno>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (v[j].idade > v[j + 1].idade) {
                swap(v[j], v[j + 1]);
            }
        }
    }
}

void selectionSort(vector<Aluno>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (v[j].nota < v[min_idx].nota) {
                min_idx = j;
            }
        }
        swap(v[i], v[min_idx]);
    }
}

void insertionSort(vector<Aluno>& v) {
    int n = v.size();
    for (int i = 1; i < n; ++i) {
        Aluno key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j].matricula > key.matricula) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}

void printAlunos(const vector<Aluno>& v, const string& criterio) {
    cout << "ordenado por " << criterio << ":" << "\n";
    for (const auto& a : v) {
        cout << a.nome << " " << a.matricula << " " << a.idade << " " << fixed << setprecision(2) << a.nota << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<Aluno> alunos;
    int cmd;

    while (cin >> cmd && cmd != 0) {
        if (cmd == 1) {
            Aluno a;
            cin >> a.nome >> a.matricula >> a.idade >> a.nota;
            alunos.push_back(a);
        } else if (cmd == 2) {
            bubbleSort(alunos);
            printAlunos(alunos, "idade");
        } else if (cmd == 3) {
            selectionSort(alunos);
            printAlunos(alunos, "nota");
        } else if (cmd == 4) {
            insertionSort(alunos);
            printAlunos(alunos, "matricula");
        }
    }

    return 0;
}