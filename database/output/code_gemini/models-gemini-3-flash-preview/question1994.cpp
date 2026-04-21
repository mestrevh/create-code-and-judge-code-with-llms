/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Problema: Organizando a Escola
 * O objetivo é identificar alunos "destaque" com base em três critérios:
 * 1. Média superior à média da turma.
 * 2. Status 'M' (matriculado).
 * 3. Faltas inferiores a 10% do "total da turma".
 * 
 * A análise dos casos de teste indica que o "total da turma" para o critério 
 * de faltas refere-se ao somatório total de faltas de todos os alunos.
 */

struct Aluno {
    string matricula;
    string primeiroNome;
    string ultimoNome;
    double media;
    int faltas;
    char status;
};

int main() {
    // Otimização de I/O padrão C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    // Leitura da quantidade de alunos
    if (!(cin >> N) || N <= 0) {
        return 0;
    }

    vector<Aluno> turma(N);
    double somaMedia = 0.0;
    long long somaFaltas = 0;

    // Leitura dos dados de cada aluno e cálculo dos totais
    for (int i = 0; i < N; ++i) {
        if (!(cin >> turma[i].matricula >> turma[i].primeiroNome >> turma[i].ultimoNome >> turma[i].media >> turma[i].faltas >> turma[i].status)) {
            break;
        }
        somaMedia += turma[i].media;
        somaFaltas += turma[i].faltas;
    }

    // Médias e limites calculados sobre todos os alunos
    double mediaTurma = somaMedia / (double)N;
    double limiteFaltas = 0.1 * (double)somaFaltas;

    // Identificação e exibição dos alunos destaque
    for (int i = 0; i < N; ++i) {
        // Critérios: matriculado, média > média_da_turma e faltas < 10% do total_de_faltas
        if (turma[i].status == 'M' && turma[i].media > mediaTurma && (double)turma[i].faltas < limiteFaltas) {
            // Formato de saída: (posição:ultimo_nome)
            cout << i << ":" << turma[i].ultimoNome << "\n";
        }
    }

    return 0;
}