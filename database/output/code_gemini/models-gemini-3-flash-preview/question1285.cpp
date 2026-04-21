/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>

using namespace std;

int calcular_nota(string resposta, string gabarito) {
    int nota = 0;
    for (int i = 0; i < 5; ++i) {
        if (resposta[i] == gabarito[i]) {
            nota++;
        }
    }
    return nota;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<string, string> alunos;
    string nome, respostas;

    while (cin >> nome && nome != "*") {
        cin >> respostas;
        alunos[nome] = respostas;
    }

    string gabarito;
    cin >> gabarito;

    if (alunos.empty()) {
        return 0;
    }

    int maior_nota = -1;
    int menor_nota = 6;
    double soma_notas = 0;
    int total_alunos = 0;

    for (auto const& [nome_aluno, resp_aluno] : alunos) {
        int nota = calcular_nota(resp_aluno, gabarito);
        if (nota > maior_nota) maior_nota = nota;
        if (nota < menor_nota) menor_nota = nota;
        soma_notas += nota;
        total_alunos++;
    }

    cout << "Maior: " << maior_nota << "\n";
    cout << "Menor: " << menor_nota << "\n";
    cout << "Media: " << fixed << setprecision(2) << (soma_notas / total_alunos) << endl;

    return 0;
}