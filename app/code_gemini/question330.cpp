/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <numeric>

struct Aluno {
    std::string codigo;
    std::string nome;
    int idade;
    int sexo;
    double nota_enem;
};

struct Disciplina {
    std::string codigo;
    std::string nome;
    std::vector<std::string> alunos_matriculados;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::map<std::string, Aluno> alunos_map;
    int masculino = 0;
    int feminino = 0;
    long long soma_idades = 0;
    long long soma_idades_enem_alto = 0;
    int count_enem_alto = 0;

    for (int i = 0; i < n; ++i) {
        Aluno a;
        std::cin >> a.codigo;
        std::cin.ignore();
        std::getline(std::cin, a.nome);
        std::cin >> a.idade >> a.sexo >> a.nota_enem;
        
        alunos_map[a.codigo] = a;

        if (a.sexo == 1) {
            masculino++;
        } else {
            feminino++;
        }

        soma_idades += a.idade;

        if (a.nota_enem > 7.5) {
            soma_idades_enem_alto += a.idade;
            count_enem_alto++;
        }
    }

    int m;
    std::cin >> m;

    std::vector<Disciplina> disciplinas_vec;
    std::map<std::string, int> disciplina_codigo_para_indice;

    for (int i = 0; i < m; ++i) {
        Disciplina d;
        std::cin >> d.codigo;
        std::cin.ignore();
        std::getline(std::cin, d.nome);
        disciplinas_vec.push_back(d);
        disciplina_codigo_para_indice[d.codigo] = i;
    }

    int p;
    std::cin >> p;
    
    for (int i = 0; i < p; ++i) {
        std::string codigo_aluno, codigo_disciplina;
        std::cin >> codigo_aluno >> codigo_disciplina;

        std::string nome_aluno = alunos_map[codigo_aluno].nome;
        int indice_disciplina = disciplina_codigo_para_indice[codigo_disciplina];
        
        disciplinas_vec[indice_disciplina].alunos_matriculados.push_back(nome_aluno);
    }

    std::cout << masculino << std::endl;
    std::cout << feminino << std::endl;

    std::cout << std::fixed << std::setprecision(2);
    
    if (n > 0) {
        std::cout << static_cast<double>(soma_idades) / n << std::endl;
    } else {
        std::cout << 0.00 << std::endl;
    }

    if (count_enem_alto > 0) {
        std::cout << static_cast<double>(soma_idades_enem_alto) / count_enem_alto << std::endl;
    } else {
        std::cout << 0.00 << std::endl;
    }

    std::sort(disciplinas_vec.begin(), disciplinas_vec.end(), [](const Disciplina& a, const Disciplina& b) {
        return a.nome < b.nome;
    });

    for (auto& disciplina : disciplinas_vec) {
        std::cout << disciplina.nome << std::endl;
        std::cout << disciplina.alunos_matriculados.size() << std::endl;

        std::sort(disciplina.alunos_matriculados.begin(), disciplina.alunos_matriculados.end());

        for (const auto& nome_aluno : disciplina.alunos_matriculados) {
            std::cout << nome_aluno << std::endl;
        }
    }

    return 0;
}
