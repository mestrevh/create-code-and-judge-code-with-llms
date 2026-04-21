/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

/**
 * Persona: Grande Mestre em Programação Competitiva.
 * Estrutura de dados: Fila de matérias (FIFO), onde cada matéria contém uma Pilha de atividades (LIFO).
 * Lógica: Remover um item por vez (se a pilha de atividades da primeira matéria estiver vazia, 
 * remove-se a matéria da fila; caso contrário, remove-se o topo da pilha de atividades).
 * Exibição: O estado atual deve ser exibido antes da primeira remoção e após cada remoção.
 */

struct Materia {
    string name;
    vector<string> activities;
};

// Função para exibir o estado atual da fila de matérias e suas pilhas de atividades.
// O formato segue rigorosamente os casos de teste: Materia seguida de atividades com 4 espaços.
void printState(const deque<Materia>& q) {
    for (const auto& m : q) {
        cout << "Materia: " << m.name << "\n";
        for (const auto& act : m.activities) {
            cout << "    Atividade: " << act << "\n";
        }
        // Uma linha em branco após cada matéria, conforme observado nos testes.
        cout << "\n";
    }
}

int main() {
    // Otimização padrão de I/O para C++ competitivo.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    deque<Materia> q;
    char type;
    string name;

    // Leitura dos dados até o fim do arquivo (EOF).
    while (cin >> type >> name) {
        if (type == 'M') {
            // Nova matéria adicionada ao fim da Fila.
            q.push_back({name, {}});
        } else if (type == 'A') {
            // Nova atividade adicionada à Pilha da matéria atual (a última da fila).
            if (!q.empty()) {
                q.back().activities.push_back(name);
            }
        }
    }

    // Exibição do estado inicial.
    printState(q);

    // Loop de remoção contínua até que a Fila de matérias esteja vazia.
    while (!q.empty()) {
        // Regra: se a primeira matéria não tem atividades, remove-se a matéria.
        if (q.front().activities.empty()) {
            q.pop_front();
        } else {
            // Caso contrário, remove-se a última atividade da primeira matéria (LIFO).
            q.front().activities.pop_back();
        }

        // Linha separadora de 17 underscores.
        cout << "_________________\n";

        // Se a fila ainda não estiver vazia, prepara-se o ambiente para o próximo estado.
        // A lógica de cout "\n" garante a linha em branco exigida entre o separador e o estado.
        if (!q.empty()) {
            cout << "\n";
            printState(q);
        } else {
            // Caso especial: se a fila esvaziou, o teste mostra uma linha em branco e um último separador.
            // Para bater com o formato específico do Teste 0, o loop principal garante as 17 underscores.
        }
    }

    return 0;
}